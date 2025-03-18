# Women Safety Night Patrolling Robot

## Overview
The **Women Safety Night Patrolling Robot** is an autonomous surveillance system designed to patrol an area at night, detect obstacles, and provide real-time monitoring through a **360-degree Full HD Wi-Fi camera with night vision**. This project enhances safety by offering continuous surveillance and automated obstacle avoidance, making it ideal for security applications.

## Features
- 🚧 **Obstacle Avoidance**: Uses three **ultrasonic sensors** to detect obstacles and navigate safely.
- 🔄 **Dual Arduino System**: Two **Arduino Uno** boards control different aspects of the robot, ensuring efficient multitasking.
- 📷 **360-Degree Surveillance**: Equipped with a **Full HD Wi-Fi camera with night vision**, allowing remote monitoring.
- 🤖 **Autonomous Patrolling**: Follows a predefined path while dynamically avoiding obstacles.
- ⚙️ **Motor Driver Control**: Uses an **L298N motor driver** to control wheel movement for smooth patrolling.

## Components Used
- **2 x Arduino Uno** (One for sensor control, another for motor and camera integration)
- **1 x Full HD Wi-Fi Camera with Night Vision** (For 360-degree surveillance)
- **3 x Ultrasonic Sensors (HC-SR04)** (For obstacle detection)
- **1 x L298N Motor Driver Module** (To control motors)
- **2 x DC Motors** (For movement)
- **1 x Battery Pack** (To power the system)
- **Wheels and Chassis** (For mobility and structure)

## How It Works
### 1️⃣ Obstacle Detection
- The **ultrasonic sensors** continuously scan the surroundings.
- If an obstacle is detected, the robot stops and changes direction.

### 2️⃣ Movement & Navigation
- The **motor driver** controls the **DC motors** to move the robot forward, turn, or stop.
- The second **Arduino Uno** processes sensor data and makes navigation decisions.

### 3️⃣ Surveillance
- The **Full HD Wi-Fi camera** transmits live footage to a remote device.
- The camera rotates **360 degrees** to cover the entire patrol area.

## Installation & Setup
### 🛠️ Assemble the Hardware
1. Attach the **ultrasonic sensors** to the front and sides of the robot.
2. Mount the **Wi-Fi camera** on a rotating platform.
3. Connect the **Arduino boards, motor driver, and motors**.

### 🔌 Upload the Code
1. Load the Arduino **obstacle avoidance and motor control** scripts onto both Arduino boards.
2. Ensure proper pin configuration in the code.

### ⚡ Power On & Operate
1. Turn on the **battery pack**.
2. Connect to the **Wi-Fi camera** for live streaming.
3. The robot starts patrolling autonomously.

## Future Enhancements
- 🔍 **AI-based facial recognition** for identifying threats.
- 📡 **GPS tracking** for real-time location updates.
- 📱 **Remote control via mobile app** for manual intervention.
- ☀️ **Solar-powered battery system** for longer operational hours.

## Contributing
Feel free to contribute by improving the design, adding new features, or optimizing the code! Fork this repository, create a new branch, and submit a pull request. 

## License
This project is open-source under the **MIT License**.

---

🚀 **Enhancing safety through smart automation!**


https://github.com/user-attachments/assets/148037f0-3d38-4178-8187-5b4e1949f220

