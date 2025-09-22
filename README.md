# 🐟 Smart Sardine Drying System

An IoT-powered system for **accelerated sardine drying** using controlled temperature and airflow. Built around the **ESP32**, this project combines sensors, actuators, and a mobile app for automated fish drying.

## 🚀 Current Features

### ✅ Implemented

- **Real-time monitoring**: Temperature, humidity, and currentWeight sensors
- **Automatic control**: Heater and fan switching based on temperature thresholds
- **LCD display**: Real-time sensor data and system status
- **Temperature thresholds**: Low (35°C) and High (45°C) with automatic switching
- **currentWeight tracking**: Load cell integration for drying progress monitoring

### 🔄 In Development

- **Flutter mobile app**: Dashboard and remote control interface
- **Bluetooth/Wi-Fi connectivity**: Remote monitoring and control
- **Battery system**: Portable operation with solar support
- **Advanced control logic**: currentWeight-based drying completion detection

## 📊 Project Status: **38% Complete**

### Hardware Design (50%)

- ✅ ESP32 MCU with Wi-Fi/Bluetooth
- ✅ DHT22 temperature/humidity sensor
- ✅ HX711 load cell for currentWeight measurement
- ✅ Heating element (Pin 14) and cooling fan (Pin 13)
- ❌ Battery system and monitoring

### Firmware (40%)

- ✅ Sensor drivers (DHT, HX711)
- ✅ Basic control logic with temperature thresholds
- ✅ LCD display system
- ❌ Data persistence and app communication

### Mobile App (25%)

- ✅ Flutter project structure
- ✅ Basic UI components
- ❌ Connectivity and control features

## 🛠️ Hardware Setup

### Components

- **ESP32 DevKit** (Main microcontroller)
- **DHT22** sensor - Temperature & humidity
- **HX711 + Load Cell** - currentWeight measurement
- **LCD I2C Display**- 16x2 character display
- **Heating Element** - Temperature control
- **Cooling Fan** - Airflow control

## 🚧 Next Development Phase

### Priority Tasks

1. **Mobile App Integration**

   - Bluetooth connectivity implementation
   - Remote control dashboard
   - Real-time data visualization

2. **Enhanced Control Logic**

   - currentWeight-based drying completion
   - Data persistence (NVS/EEPROM)
   - System monitoring and alerts

3. **Power Management**
   - Battery system design
   - Solar charging capability
   - Low-power operation modes

## 📁 Project Structure

```
IoT-sardines-drying-system/
├── src/main.cpp              # ESP32 firmware
├── drying_system/            # Flutter mobile app
├── circuit/                  # Hardware designs
├── lib/GUIDELINE.md          # Development roadmap
└── platformio.ini           # Build configuration
```

## 🔧 Getting Started

### Firmware Setup

1. Install PlatformIO
2. Clone repository
3. Connect hardware according to pin configuration
4. Upload firmware to ESP32
5. Monitor via Serial (115200 baud) or LCD display

### Mobile App Setup

```bash
cd drying_system
flutter pub get
flutter run
```

## 📈 Performance Goals

- **Drying Time**: 50% faster than traditional sun-drying
- **Quality Control**: Consistent temperature and humidity
- **Energy Efficiency**: Solar-powered operation
- **User Experience**: Intuitive mobile control

---

**Status**: Active Development | **Version**: 0.4.0 | **Last Updated**: September 2025
