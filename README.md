# Smart Home Automation Using ATmega32

## 📌 Project Overview
This project implements a **smart home automation system** using an **ATmega32 microcontroller** to control lighting, fan speed, and fire detection based on environmental conditions. It features real-time monitoring and an LCD display for status updates.

## 🎯 Features
- **Lighting Control**: Adjusts LED brightness based on ambient light using an **LDR sensor**.
- **Fan Speed Control**: Regulates fan speed with **PWM** based on room temperature (**LM35 sensor**).
- **Fire Detection & Alert**: Uses a **Flame Sensor** to detect fire, triggering an alarm and LCD alert.
- **Real-time LCD Display**: Shows temperature, fan status, and light intensity.
- **Buzzer Alerts**: Activates during fire detection for safety.

## ⚙️ Hardware Components
| Component           | Description  |
|--------------------|--------------|
| **Microcontroller** | ATmega32 |
| **Light Sensor**   | LDR (Light Dependent Resistor) |
| **Temperature Sensor** | LM35 |
| **Flame Sensor** | Detects fire and triggers alerts |
| **LCD Display** | 16x2 LCD for system status |
| **Fan Motor** | Controlled via PWM and H-Bridge |
| **LEDs** | 3 LEDs (Red, Green, Blue) for light intensity |
| **Buzzer** | Activates during fire alerts |
| **H-Bridge Circuit** | Controls fan motor speed |

## 🔌 System Requirements
- **Microcontroller**: ATmega32
- **System Frequency**: 16 MHz

## 🛠️ Operation Description
### 🔆 Lighting Control
- **LDR sensor** detects ambient light intensity.
- **LEDs** adjust brightness based on pre-set thresholds.

### 🌡️ Temperature-Based Fan Control
- **LM35 sensor** measures temperature.
- Fan speed is adjusted using **PWM** signals based on specific temperature ranges.

### 🔥 Fire Detection & Alert System
- **Flame sensor** detects fire and triggers:
  - **LCD alert** displaying "Critical Alert!"
  - **Buzzer activation** for safety warning.
  - **Continuous alert mode** until fire is no longer detected.

### 📟 LCD Display Output
- **Fan Status**: ON/OFF
- **Temperature**: Real-time reading
- **Light Intensity**: LED status based on brightness
- **Fire Alerts**: Displays warnings when fire is detected

## 📺 Demo


https://github.com/user-attachments/assets/35972174-3137-4e7a-97d7-f76152f1b6d7


## 🚀 How to Run
1. **Assemble the circuit** using the components listed.
2. **Flash the code** onto the ATmega32 microcontroller.
3. **Power up the system** and observe:
   - LEDs adjust based on light intensity.
   - Fan speed varies according to temperature.
   - Fire detection system alerts upon detecting flames.

## 🚀 Future Enhancements
- **IoT Integration** for remote monitoring and control.
- **Bluetooth/WiFi Module** for smartphone app connectivity.
- **Voice Control** using a voice recognition module.
- **Enhanced Fire Safety Mechanism** to trigger automatic water sprinklers.


