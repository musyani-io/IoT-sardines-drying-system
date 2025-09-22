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

## 📊 Project Status: **52% Complete**

### Hardware Design (75%)

- ✅ ESP32 MCU with Wi-Fi/Bluetooth
- ✅ DHT22 temperature/humidity sensor
- ✅ HX711 load cell for currentWeight measurement
- ✅ Heating element (Pin 14) and cooling fan (Pin 13)
- ✅ Weight Initiation Button
- ✅ Battery system design
- ❌ Add buttons for settings mode, UP, and DOWN
- ❌ Add battery level monitoring (voltage divider or fuel gauge IC)
- ❌ Add a temperature sensor for the circuit board
- ❌ Design PCB (schematic + layout + fabrication + assembly)

### Firmware (55%)

- ✅ Sensor drivers (DHT, HX711)
- ✅ Basic control logic with temperature thresholds
- ✅ LCD display system
- ✅ Data persistence and app communication
- ❌ Implement automatic control logic for settings mode buttons
- ❌ Store thresholds (temperature, currentWeight, time) in NVS/EEPROM
- ❌ Implement threshold update via app (apply in real time)
- ❌ Monitor system (uptime, ON/OFF status, drying completion, battery level)
- ❌ Implement communication protocol (send sensor values, receive commands)

### Mobile App (40%)

- ✅ Flutter project structure
- ✅ Basic UI components
- ✅ Basic Bluetooth connectivity
- ❌ Build dashboard UI (battery level, system status)
- ❌ Build control panel (remote ON/OFF, update thresholds)
- ❌ Add connectivity layer (Wi-Fi/Cloud, MQTT client or HTTP client)
- ❌ Implement notifications (drying complete, error/low battery)
- ❌ Add history/log screen (optional)
