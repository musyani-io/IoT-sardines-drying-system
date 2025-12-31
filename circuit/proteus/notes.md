# NOTES

## IMPORTANT CONCEPTS

- So, the _varistor (R2)_ to be connected between neutral line and earth line cannot work in simulation (proteus), since it considers just 0V as its reference but in real-life, the enclosed case (earth will be connected to the said varistor).

## COMPONENTS AND THEIR DESCRIPTIONS

### POWER SUPPLY PART

- **Fuse (F1)**: Voltage rated at 250V, current 1.6V.
- **NTC Thermistor (USB1)**: Current rushing limiter to protect the transformer. Rated at 5Ω (25°C)
- **Varistor (R1)**: Takes care of voltage spikes from the source. Rated at 275AC (Varistor voltage), 710DC (Clamping Voltage).
- **Varistor (R2)**: Takes care of spikes to the grounding (enclosure to be designed). Same specifications as **R1**. Not present in simulation due to a concept explained in _important concepts_.
