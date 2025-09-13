# Smart-Blindness-Assistance-Cap

This project aims to enhance the mobility and independence of visually impaired individuals by creating a wearable assistive hat.  
The hat integrates **ultrasonic sensors**, **Bluetooth communication**, **MP3 audio alerts**, and **haptic feedback** to provide real-time information about the environment.  

---

## 🚀 Features
- ✅ Obstacle detection using ultrasonic sensors.  
- ✅ Audio feedback with MP3 module and speaker.  
- ✅ Bluetooth control and buzzer alerts.  
- ✅ Wearable, hands-free design for daily mobility.  

---

## 📂 Repository Structure
Arduino/ → Arduino codes for Ultrasonic+MP3 and Bluetooth+Buzzer
Python/ → Object detection code (adapted from salar-dev’s repo)
---

## 🛠️ Hardware Setup
- Arduino Uno / Nano  
- Ultrasonic Sensor (HC-SR04)  
- DFPlayer Mini MP3 Module + Speaker  
- HC-01 Bluetooth Module  
- Buzzer  
- Power Supply (USB / Battery Pack)  

---

## 🧑‍💻 Software
- Arduino IDE  
- Python 3.x  
- OpenCV (for object detection)  
- PySerial (for Arduino-Python communication if extended)  

---

## 📑 Report
The full project documentation (introduction, problem statement, objectives, innovation, hardware setup, flowcharts, testing, and results) is available in [`docs/Report.pdf`](docs/Report.pdf).  

---

## 📜 Arduino Codes
- `ultrasonic_mp3.ino` → Uses ultrasonic sensor to detect objects and trigger MP3 playback.  
- `bluetooth_buzzer.ino` → Uses Bluetooth to control a buzzer for haptic/audio feedback.  

---

## 🤖 Python Code
The repository also includes an **object detection module** (for object identification), adapted from [salar-dev/python-object-detection-opencv](https://github.com/salar-dev/python-object-detection-opencv).  

---

## 🙏 Credits
- Arduino codes written and tested by our team.  
- Object Detection code adapted from [salar-dev/python-object-detection-opencv](https://github.com/salar-dev/python-object-detection-opencv).  

⚠️ This repository is for **educational purposes only**.  

---
