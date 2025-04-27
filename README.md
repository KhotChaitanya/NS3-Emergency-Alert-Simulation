# Emergency Alert Dissemination Simulation using NS-3

## Overview
This project simulates the transmission and visualization of emergency alerts (Fire and Flood) across a hybrid wireless network using NS-3. It demonstrates decentralized communication using a mix of Star and Mesh topologies in a Wi-Fi Ad-Hoc network setup.

## Features
- Central Control Center node broadcasting alerts.
- Node-level behavior upon receiving different alerts (Sprinkler activation, Barrier deployment).
- Alternate transmission of FIRE (100 bytes) and FLOOD (150 bytes) alerts via UDP.
- CSV logging for alert analytics.
- NetAnim visualization of packet flows.
- Real-world inspired disaster communication modeling.

## Tools & Technologies
- NS-3 (Network Simulator 3)
- C++ for simulation logic
- NetAnim for visualization
- Python/Excel for CSV-based graph plotting

## How to Run
1. Install NS-3 on your machine.
2. Clone this repository.
3. Compile and run the `alert_simulation.cc` file.
4. Use NetAnim to visualize the `behavior_alert.xml` output.
5. Analyze `alert_log.csv` for transmission data.

## Output

### 1. Terminal Output Showing Alerts and Reactions:

This screenshot displays the terminal output where the Control Centre is sending alternate FIRE and FLOOD alerts to the receiver nodes. The nodes respond with appropriate messages such as:
- "Sprinkler system activated" for FIRE
- "Flood barrier raised" for FLOOD

![image](https://github.com/user-attachments/assets/3fd6df2a-18bd-40a2-ac1d-b08dd2fb4723)
![image](https://github.com/user-attachments/assets/c0cba2f3-7cd4-4bbf-8347-00f981ed46d0)
![image](https://github.com/user-attachments/assets/9df847da-7e3b-4a13-9304-df2eb007a82c)
![image](https://github.com/user-attachments/assets/447413a3-6ca2-4647-b983-61b10170cb76)

It also logs packet receive time and alert type clearly, demonstrating how each node reacts based on the alert received.

### 2. NetAnim Packet Flow Visualization:

This visualization shows nodes arranged in a circular layout representing a star topology, with arrows indicating packet movement from the Control Centre to receiver nodes.

![image](https://github.com/user-attachments/assets/5f83d665-a8bc-4a17-949e-d14528f64409)
![image](https://github.com/user-attachments/assets/a9880ab0-d4c1-4527-92c3-2068bd104ee7)
![image](https://github.com/user-attachments/assets/b415ef51-e714-4393-96c8-250e68ad4523)
![image](https://github.com/user-attachments/assets/11765e82-2677-4406-968d-fe19593548e7)
![image](https://github.com/user-attachments/assets/fc0f960c-eab3-4878-9e98-b40dfefc8164)
![image](https://github.com/user-attachments/assets/ea175e7f-6439-4f07-a5af-b771efab91cf)


### 3. Graphical Representation of Alerts Using Python:

A bar graph generated from the `alert_log.csv` file shows the number of FIRE and FLOOD alerts sent over simulation time.

![image](https://github.com/user-attachments/assets/ddffd858-597d-4bdb-9e58-cdad0fc63b39)


## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Author
KhotChaitanya
