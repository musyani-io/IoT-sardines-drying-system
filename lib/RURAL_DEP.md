# 🌍 Rural Deployment Guidelines — Smart Sardine Drying System

This checklist focuses on making the system reliable in rural environments by addressing **power & energy**, **connectivity**, and **usability for non-technical users**.

---

## 🔋 Power & Energy

- [ ] **Solar + Battery System**

  - [ ] Add solar panel sized for daily usage + 30% headroom.
  - [ ] Install solar charge controller (MPPT preferred, PWM acceptable).
  - [ ] Use battery pack sized for 2–3 days autonomy.
  - [ ] Prefer LiFePO4 for safety & long cycle life (Li-ion with BMS acceptable).

- [ ] **Robust Charging & Protection**

  - [ ] Add BMS or protected battery pack (over/under-voltage, balancing).
  - [ ] Add inline fuse on battery input.
  - [ ] Add reverse-polarity diode.

- [ ] **Power Budgeting & Low Power Modes**

  - [ ] Measure heater + fan draw vs ESP32 idle draw.
  - [ ] Enable deep sleep on ESP32 when idle.
  - [ ] Wake MCU on schedule or button.

- [ ] **Fallback Power Option**
  - [ ] Provide 12 V DC input (barrel or terminal) for generator/car battery backup.

---

## 📡 Connectivity

- [ ] **Local-First Operation**

  - [ ] Ensure full device control via BLE or local Wi-Fi.
  - [ ] App should function without internet.

- [ ] **Cellular Option (Optional)**

  - [ ] Add GSM/LTE module (e.g., SIM800L or SIM7600).
  - [ ] Implement SMS alerts for key events (drying complete, overtemp, low battery).

- [ ] **Store-and-Forward**
  - [ ] Buffer data locally (flash storage).
  - [ ] Sync logs when connection is restored.

---

## 👩‍🌾 Usability for Non-Technical Users

- [ ] **Local UI**

  - [ ] Add small OLED/7-seg + 3 buttons for:
    - [ ] Start/Stop
    - [ ] Threshold adjust
    - [ ] Tare weight

- [ ] **Clear Indicators**

  - [ ] LEDs/icons for:
    - [ ] Power
    - [ ] Heater active
    - [ ] Fan active
    - [ ] Low battery
    - [ ] Error state

- [ ] **Physical Instructions**

  - [ ] Print sticker with 3-step operating instructions.
  - [ ] Add QR code linking to longer manual.

- [ ] **Language & Literacy**
  - [ ] Use simple words or icons in UI.
  - [ ] Support icon-only operation for universal usability.

---
