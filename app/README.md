# app

Flutter IoT app integrated with a drying system.

## Guidelines

- [x] Set up Flutter project
- [ ] Build dashboard UI:
  - [ ] Show temperature & humidity
  - [ ] Show weight
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
