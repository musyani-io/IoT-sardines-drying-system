# PCB Design Flow Checklist — Smart Sardine Dryer (ESP32)

## Step 1 — Power Supply & Protection

- [ ] Start with input power source (battery/adapter/solar)
- [ ] Add reverse polarity protection (diode/MOSFET) + main fuse
- [ ] Design buck regulator (5V → 3.3V) with decoupling caps for ESP32 Wi-Fi spikes
- [ ] Place bulk capacitor (10–47 µF) near input; 0.1 µF ceramics at MCU pins
- [ ] Add TVS diode for surge/transient protection
- [ ] Provide test point for Vcc, GND, and battery sense line

---

## Step 2 — MCU & Core Circuit

- [ ] Place ESP32 module footprint; follow antenna clearance rules
- [ ] Add EN/BOOT buttons, pull-ups, and UART programming header
- [ ] Place crystal (if needed) and decoupling per datasheet
- [ ] Route power and ground planes under MCU before peripherals

---

## Step 3 — Signal Conditioning (Sensors & ADC)

- [ ] Place HX711 close to load cell connector; keep analog traces short
- [ ] Use star ground for analog return; tie to digital ground at single point
- [ ] Add RC filter if sensor noise is expected
- [ ] Battery monitoring: divider → optional op-amp buffer → ADC pin, with series resistor
- [ ] Add test pads for calibration (tare/offset)

---

## Step 4 — Actuator Drivers (Heater & Fan)

- [ ] Select driver type:
  - [ ] DC loads: logic-level MOSFET + gate resistor + flyback diode
  - [ ] AC heater: external SSR/triac module
- [ ] Add snubber or TVS across noisy loads
- [ ] Size traces for current (use calculator for copper width)
- [ ] Place drivers near output connectors; keep loop area small

---

## Step 5 — Safety & Redundancy

- [ ] Add thermal fuse/thermostat in heater line
- [ ] Add current sense resistor or module for heater/fan monitoring
- [ ] Provide manual override or E-stop header
- [ ] Maintain creepage/clearance ≥8 mm for mains isolation

---

## Step 6 — Communication Interfaces

- [ ] Add pull-ups and series resistors for I²C/SPI if needed
- [ ] Place connectors for sensors (DHT, load cell) with keyed orientation
- [ ] Provide pads for optional OLED/debug I²C screen
- [ ] Route comm lines away from high-current traces

---

## Step 7 — Antenna & RF Hygiene

- [ ] Respect ESP32 antenna keep-out zone (no copper or tall parts)
- [ ] Keep switching regulators away from antenna region
- [ ] Add ground stitching vias around noisy circuits

---

## Step 8 — Peripheral Connections

- [ ] Place connectors for heater, fan, sensors, and battery
- [ ] Use locking/keyed connectors for field reliability
- [ ] Route high-current traces last; separate from signals
- [ ] Add polarity marks and silkscreen labels

---

## Step 9 — Testability & Debug

- [ ] Add test points for Vcc, GND, sensor lines, MOSFET gates, and battery sense
- [ ] Place status LEDs: Power, Wi-Fi, Heater ON
- [ ] Provide UART header for logs + programming

---

## Step 10 — Final Checks & Production

- [ ] Run ERC (electrical rule check) and DRC (design rule check)
- [ ] Verify creepage/clearance for heater/fan supply
- [ ] Check copper widths vs current loads
- [ ] Generate Gerbers, BOM, and assembly notes
- [ ] Order small prototype batch and smoke-test power rails

---

## Step 11 — Field Testing

- [ ] Assemble board with sensors + actuators
- [ ] Power-up sequence: rails → logic → actuators
- [ ] Measure regulator/MOSFET temps under heater load
- [ ] Run full drying cycle; log sensor stability, cutoff response, completion
