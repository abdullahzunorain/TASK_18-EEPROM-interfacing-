# Task 18: EEPROM Interfacing with 24C02

This project demonstrates how to interface with the 24C02 EEPROM using a software-based I2C driver. The task involves reading and writing data to/from the EEPROM, implementing a 1-second counter, and preserving the counter value across system resets.

## Steps

### 1. Study the EEPROM Datasheet
- First, study the datasheet of the EEPROM IC 24C02: [24C02 Datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/21202j.pdf).
- This will provide you with detailed information on how to interact with the EEPROM, its specifications, timing requirements, and communication protocol.

### 2. Write a Software-Based I2C Driver
- Implement a software-based I2C driver to communicate with the 24C02 EEPROM.
- The driver should be able to:
  - **Read** data from EEPROM.
  - **Write** data to EEPROM.

### 3. Implement a 1-Second Counter
- Create an 8-bit counter that increments every 1 second.
- **Save the counter value** to the EEPROM after each second.
- Display the current counter value on a **seven-segment display**.
- On system **startup**, load the counter value from the EEPROM to ensure it is restored after resets.
  - An unwritten memory location in the EEPROM holds the value `0xFF` (255). This can be used to check if the EEPROM is fresh or if the counter value is legitimate.

### 4. Increase the Write Interval to Preserve EEPROM Life
- **EEPROMs have limited write cycles**. Writing too frequently can wear out the EEPROM.
- Refer to the EEPROM's datasheet to determine the **number of write cycles** supported by the device.
- Calculate the delay between writes to ensure that the EEPROM will last at least **10 years**.
  - Adjust the counter so that it writes to EEPROM at intervals that align with this goal.

### 5. Implement a 32-Bit Counter
- Extend the previous implementation to handle a **32-bit (4 bytes) counter**.
- Use **4 adjacent memory locations** in the EEPROM to store the 32-bit counter value.
- To handle 32-bit data:
  - Use bitwise shifts (`>>`, `<<`) and bitwise OR (`|`) to **assemble a 4-byte value** from individual bytes.
  - Similarly, use bitwise shifts and AND (`&`) operators to **separate the 4-byte value** into individual bytes.

---

