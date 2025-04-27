#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/internet-module.h"
#include "ns3/wifi-module.h"
#include "ns3/netanim-module.h"
#include <fstream>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("AlertBehaviorSim");

std::ofstream logFile;

void FireResponse (uint32_t nodeId) {
  NS_LOG_UNCOND (Simulator::Now ().GetSeconds () << "s [Node " << nodeId << "] activates sprinkler system (FIRE RESPONSE)");
}

void FloodResponse (uint32_t nodeId) {
  NS_LOG_UNCOND (Simulator::Now ().GetSeconds () << "s [Node " << nodeId << "] raising sand barriers (FLOOD RESPONSE)");
}

void ReceivePacket (Ptr<Socket> socket) {
  Ptr<Packet> packet;
  Address from;
  uint32_t nodeId = socket->GetNode ()->GetId ();
  while ((packet = socket->RecvFrom (from))) {
	if (packet->GetSize () > 0) {
  	std::string pktType = packet->GetSize () == 100 ? "FIRE" : "FLOOD";
  	NS_LOG_UNCOND (Simulator::Now ().GetSeconds () << "s Node " << nodeId << " received " << pktType << " ALERT");
  	if (pktType == "FIRE")
    	Simulator::ScheduleNow (&FireResponse, nodeId);
  	else
    	Simulator::ScheduleNow (&FloodResponse, nodeId);
	}
  }
}

void SendAlerts (std::vector<Ptr<Socket>> sockets, std::vector<Ipv4Address> dests, uint16_t port, bool fireAlert) {
  uint32_t size = fireAlert ? 100 : 150;
  std::string type = fireAlert ? "FIRE" : "FLOOD";


  for (size_t i = 0; i < sockets.size (); ++i) {
	Ptr<Packet> packet = Create<Packet> (size);
	sockets[i]->SendTo (packet, 0, InetSocketAddress (dests[i], port));
	logFile << Simulator::Now ().GetSeconds () << "," << type << "," << size << "," << dests[i] << "\n";
  }

  Simulator::Schedule (Seconds (2.0), &SendAlerts, sockets, dests, port, !fireAlert);
}

int main (int argc, char *argv[]) {
  CommandLine cmd;
  cmd.Parse (argc, argv);

  logFile.open ("alert_log.csv");
  logFile << "Time,Type,Size,Destination\n";

  uint32_t n = 8;
  NodeContainer nodes;
  nodes.Create (n);

  MobilityHelper mobility;
  Ptr<ListPositionAllocator> pos = CreateObject<ListPositionAllocator> ();
  pos->Add (Vector (50.0, 50.0, 0.0));
  for (uint32_t i = 1; i < n; ++i) {
	double angle = (2 * M_PI * i) / (n - 1);
	double x = 50.0 + 30.0 * cos (angle);
	double y = 50.0 + 30.0 * sin (angle);
	pos->Add (Vector (x, y, 0.0));
  }
  mobility.SetPositionAllocator (pos);
  mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  mobility.Install (nodes);

  WifiHelper wifi;
  wifi.SetStandard (WIFI_STANDARD_80211b);
  wifi.SetRemoteStationManager ("ns3::ConstantRateWifiManager", "DataMode", StringValue ("DsssRate1Mbps"));

  YansWifiPhyHelper phy = YansWifiPhyHelper::Default ();
  YansWifiChannelHelper channel = YansWifiChannelHelper::Default ();
  phy.SetChannel (channel.Create ());

  WifiMacHelper mac;
  mac.SetType ("ns3::AdhocWifiMac");

  NetDeviceContainer devices = wifi.Install (phy, mac, nodes);



  InternetStackHelper stack;
  stack.Install (nodes);

  Ipv4AddressHelper address;
  address.SetBase ("10.1.4.0", "255.255.255.0");
  Ipv4InterfaceContainer interfaces = address.Assign (devices);

  uint16_t port = 9999;
  for (uint32_t i = 1; i < n; ++i) {
	Ptr<Socket> sink = Socket::CreateSocket (nodes.Get (i), UdpSocketFactory::GetTypeId ());
	InetSocketAddress local = InetSocketAddress (Ipv4Address::GetAny (), port);
	sink->Bind (local);
	sink->SetRecvCallback (MakeCallback (&ReceivePacket));
  }

  std::vector<Ptr<Socket>> sourceSockets;
  std::vector<Ipv4Address> destAddrs;

  for (uint32_t i = 1; i < n; ++i) {
	Ptr<Socket> src = Socket::CreateSocket (nodes.Get (0), UdpSocketFactory::GetTypeId ());
	src->Connect (InetSocketAddress (interfaces.GetAddress (i), port));
	sourceSockets.push_back (src);
	destAddrs.push_back (interfaces.GetAddress (i));
  }

  Simulator::Schedule (Seconds (1.0), &SendAlerts, sourceSockets, destAddrs, port, true);

  AnimationInterface anim ("behavior_alert.xml");
  anim.EnablePacketMetadata ();
  for (uint32_t i = 0; i < n; ++i) {
	std::string label = (i == 0) ? "Control Center" : "Node " + std::to_string (i);
	anim.UpdateNodeDescription (nodes.Get (i), label);
	anim.UpdateNodeColor (nodes.Get (i), 255, 0, 0);
  }

  Simulator::Stop (Seconds (20.0));
  Simulator::Run ();
  Simulator::Destroy ();

  logFile.close ();
  return 0;
}
