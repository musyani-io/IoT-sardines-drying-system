## Optimization Checklist

- [ ] Debouncing Logic: Improve the debouncing logic in the `checkButton` function.
- [ ] LCD Updates: Update only the changed parts of the LCD screen to reduce flickering.
- [ ] DHT Readings: Reduce the frequency of DHT sensor readings.
- [ ] String Concatenation: Optimize string concatenation using `String.concat()` or `sprintf()` if necessary.
- [ ] Floating Point Operations: Minimize floating-point operations where possible.
- [ ] Weight Calculation: Rate-limit the serial outputs related to weight calculation.
- [ ] Blocking `while` Loops in `setup()`: Replace blocking `while` loops in `setup()` with a non-blocking approach.
- [x] Unnecessary `Serial.println` statements: Remove or comment out unnecessary `Serial.println` statements.
