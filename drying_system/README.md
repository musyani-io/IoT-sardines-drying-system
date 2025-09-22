# drying_system

An app to remotely control and observe system's and environmental condition around the system remotely.

## Guidelines

- [x] Set up Flutter project
- [ ] Build dashboard UI:
  - [x] Show temperature & humidity
  - [x] Show currentWeight
  - [ ] Show battery level
  - [ ] Show system status (ON/OFF, drying complete, error)
- [ ] Build control panel:
  - [ ] Remote ON/OFF control
  - [ ] Update thresholds (temperature, currentWeight, drying duration)
- [ ] Add connectivity layer:
  - [ ] For Bluetooth: integrate `flutter_blue_plus`
  - [ ] For Wi-Fi/Cloud: use MQTT client or HTTP client
- [ ] Implement notifications:
  - [ ] Alert on drying complete
  - [ ] Alert on error/low battery
- [ ] Add history/log screen (optional)
