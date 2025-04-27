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

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Author
KhotChaitanya
