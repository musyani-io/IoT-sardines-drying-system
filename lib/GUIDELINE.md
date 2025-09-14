# 🐟 Smart Sardine Drying System with IoT App

## Hardware Design

- [x] Select **ESP32** as main MCU (Wi-Fi + Bluetooth inbuilt)
- [x] Add DHT11/DHT22 sensor for temperature & humidity
- [x] Add load cell + HX711 for weight measurement
- [x] Add heating element (resistive heater / IR lamp)
- [x] Add cooling fan (DC)
- [ ] Add buttons for editing on-site (Settings and weight initiation)
- [ ] Add battery system (with capacity planning)
- [ ] Add battery level monitoring (voltage divider or fuel gauge IC)
- [ ] Add a temperature sensor for the circuit board
- [ ] Design PCB (schematic + layout + fabrication + assembly)

## Firmware (ESP32)

- [x] Write driver to read DHT sensor
- [x] Write driver to read HX711 (load cell)
- [ ] Implement automatic control logic:
  - [x] Switch heater ON/OFF based on temperature threshold
  - [x] Switch fan ON/OFF based on temperature threshold
  - [ ] Button to initate the weight value
  - [ ] Buttons for settings mode (threshold control)
  - [ ] Track drying progress using weight reduction
- [ ] Store thresholds (temperature, weight, time) in **NVS/EEPROM**
- [ ] Implement threshold update via app (apply in real time)
- [ ] Monitor system:
  - [ ] Track uptime (time ON)
  - [ ] Report ON/OFF status
  - [ ] Report drying completion
  - [ ] Report battery level
- [ ] Implement communication protocol:
  - [ ] Send sensor values + system states (JSON or string format)
  - [ ] Receive commands from app (start/stop, threshold updates)
  - [ ] Support both Wi-Fi (MQTT/HTTP) and Bluetooth (BLE) modes

## IoT Backend (Optional)

- [ ] Decide architecture:
  - [ ] Direct device ↔ app (Bluetooth)
  - [ ] Device ↔ cloud (MQTT / Firebase / ThingsBoard) ↔ app
- [ ] If cloud: set up broker/database and expose API

## Flutter Mobile App

- [x] Set up Flutter project
- [ ] Build dashboard UI:
  - [x] Show temperature & humidity
  - [x] Show weight
  - [ ] Show battery level
  - [ ] Show system status (ON/OFF, drying complete, error)
- [ ] Build control panel:
  - [ ] Remote ON/OFF control
  - [ ] Update thresholds (temperature, weight, drying duration)
- [ ] Add connectivity layer:
  - [ ] For Bluetooth: integrate `flutter_blue_plus`
  - [ ] For Wi-Fi/Cloud: use MQTT client or HTTP client
- [ ] Implement notifications:
  - [ ] Alert on drying complete
  - [ ] Alert on error/low battery
- [ ] Add history/log screen (optional)

## Testing & Validation

- [ ] Test heater/fan switching accuracy
- [ ] Validate DHT readings
- [ ] Validate load cell readings
- [ ] Cross-check battery monitoring with multimeter
- [ ] Test NVS/EEPROM persistence of thresholds
- [ ] Test real-time threshold updates from app
- [ ] Verify communication between ESP32 and app
- [ ] Perform full drying cycle test with monitoring

## Documentation & Wrap-Up

- [ ] Write README with wiring diagrams and screenshots
- [ ] Record performance (time saved vs sun-drying)
- [ ] Open-source firmware + app (optional)
- [ ] Celebrate with properly dried sardines
