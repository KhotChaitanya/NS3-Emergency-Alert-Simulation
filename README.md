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

![1](https://github.com/user-attachments/assets/11d1dd5a-7a83-4936-bf4b-fa411c72bb46)
![2](https://github.com/user-attachments/assets/ff5790a8-81e2-4a6d-add5-e711f459db4f)
![3](https://github.com/user-attachments/assets/761decfc-2393-4ea3-9ffa-77a78d63520c)
![4](https://github.com/user-attachments/assets/36cd4a2a-c841-4f6a-b8f5-d54c1dee0f05)

It also logs packet receive time and alert type clearly, demonstrating how each node reacts based on the alert received.

### 2. NetAnim Packet Flow Visualization:

This visualization shows nodes arranged in a circular layout representing a star topology, with arrows indicating packet movement from the Control Centre to receiver nodes.

![5](https://github.com/user-attachments/assets/5a31bd6c-37dc-46c2-ac5c-61cafab96255)
![6](https://github.com/user-attachments/assets/c5ff12d7-b852-4858-8207-8d0817d596bd)
![7](https://github.com/user-attachments/assets/f0014fad-3494-42e9-b4d3-9f42b53f6a51)
![8](https://github.com/user-attachments/assets/25493b3b-397d-4c18-a9a4-ca382c3ddf03)
![9](https://github.com/user-attachments/assets/d9165d1b-6a2b-42f2-afeb-8bdca899ed85)
![10](https://github.com/user-attachments/assets/7be35045-c16e-4295-9a09-b81f0aaa2838)

### 3. Graphical Representation of Alerts Using Python:

A bar graph generated from the `alert_log.csv` file shows the number of FIRE and FLOOD alerts sent over simulation time.

![plot](https://github.com/user-attachments/assets/0927b64c-4e59-4f1b-8915-c90749a2abaf)

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Author
KhotChaitanya
