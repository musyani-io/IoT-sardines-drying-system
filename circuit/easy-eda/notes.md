# NOTES

## IMPORTANT CONCEPTS

- The power supply design can provide a supply of (0-12)V with current of 2A, due to the transformer (<50VA) and buck converter for such kind of rating. So, if a transformer (>180VA), a buck converter should be changed too to provide a wider range.
- So, the _varistor (R2)_ to be connected between neutral line and earth line cannot work in simulation (proteus), since it considers just 0V as its reference but in real-life, the enclosed case (earth will be connected to the said varistor).

## COMPONENTS AND THEIR DESCRIPTIONS

### POWER SUPPLY PART

- **Fuse (F1)**: Voltage rated at 250V, current 1.6V.
- **NTC Thermistor (USB1)**: Current rushing limiter to protect the transformer. Rated at 5Ω (25°C)
- **Varistor (R1)**: Takes care of voltage spikes from the source. Rated at 275AC (Varistor voltage), 710DC (Clamping Voltage).
- **Varistor (R2)**: Takes care of spikes to the grounding (enclosure to be designed). Same specifications as **R1**. Not present in simulation due to a concept explained in _important concepts_.
- **Snubber network (R4 & C1)**: Rated at 100Ω and 100nF respectively. Purpose is to reduce noise as soon as the diodes are off by consuming the remaining charge.
- **Bridge rectifier**: Changes AC to DC (full - wave) rated at 1000V, 8A.
- **NTC Thermistor (R3)**: Acts as a current rushing limiter to protecting the transformer from the charging capacitors (smoothing)
- **Smooothing Capacitors (C2 & C3)**: Both at rated at 63V, 10000uF. Smoothens the ripple from a DC rectified voltage.
- **Filtering capacitors (C5 & U7)**: Electrolytic (35V, 100uF) for filtering low frequency spikes and Ceramic (16V, 10uF) for high frequency spikes smoothing entering the buck converter.
- **Variable resistors (R5 & VR1)**: VR1 (10kΩ) for controlling the _TRIM_ voltage up to 30V, and R5 (1kΩ) for ranging the voltage between 0V and 12V.
- **Noise cancellation capacitors (C4 & U5)**: From the _CTRL_ and _TRIM_ pins, these capacitors suppress noise to clear signals.
- **Filtering capacitors (C6 & U8)**: Polymer capacitor (35V, 330uF) with suitable temperature rise, and ceramic (16V, 10uF) for output from the buck converter.
