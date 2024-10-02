# Smart Attendance System

## Overview
> The **Smart Attendance System** is designed to offer a fool-proof solution for tracking attendance using a combination of RFID tagging and PIR sensors. The system ensures secure and accurate attendance logging by confirming both entry and exit, reducing common loopholes often found in traditional attendance systems. This project was showcased at the **ECE Department Expo** at **PSG iTech**.

## Hardware Components
> - Arduino UNO
> - PIR Sensors (2 units)
> - RFID Sensor

## Software
> - Arduino IDE
> - External RFID library (to be installed via Arduino IDE)

## How it Works
> The system operates using two **PIR Sensors**, one positioned at the entry point and another at the exit. The process works as follows:
> 1. When a student triggers the entry PIR sensor, their presence is noted.
> 2. The student then tags their RFID card for identification.
> 3. The system registers attendance only if the second PIR sensor (at the exit) confirms their movement through the entry point.
> 
> If students attempt to bypass the process or exit without properly completing the steps, specific conditionals handle and invalidate such attempts, ensuring accurate attendance logging.

## Installation and Setup
> 1. Clone or download the code from this repository.
> 2. Install the required RFID package in Arduino IDE (details in the code comments).
> 3. Connect the components (Arduino, RFID sensor, PIR sensors) following the prototype image provided.
> 4. Upload the code to your Arduino UNO board.
> 5. Test the system by simulating entry and exit movements.

## Contribution
> Contributions are welcome! Feel free to fork the repository and create pull requests with new features or improvements.

## Contact
> For any queries or suggestions, contact:
> - Email: m.dousik@gmail.com
> - LinkedIn: [Dousik Manokaran](https://www.linkedin.com/in/dousikmanokaran)
