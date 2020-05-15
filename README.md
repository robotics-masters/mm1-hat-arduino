# mm1-hat-arduino
Repository for storing Arduino related files and custom board definition.


## Arduino IDE

Copy and paste the following URL into the File > Preferences > "Additional Boards Manager" textbox.

```
https://raw.githubusercontent.com/robotics-masters/mm1-hat-arduino/master/custom_board/package_robohat_index.json
```

The latest version is 0.0.26

Make sure to also install the Arduino SAMD Library at the same time.

Boards > "Add board definition" > Search for "Robotics Masters" > Install Robo HAT Library

Boards > "Add board definition" > Search for "SAMD" > Install Arduino SAMD Library

## Serial Ports

A number of predefined serial ports are in the Robo HAT MM1 M4 boards.

- Serial - USB
- Serial1 - Raspberry Pi Serial Ports (SERCOM1)
- Serial2 - GPS Serial Port (SERCOM5)
- Serial3 - GROVE Serial Port (SERCOM0)


