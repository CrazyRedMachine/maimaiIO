## Maimai buttons

This is a firmware to use Maimai arcade buttons.

Maimai buttons are photointerrupters instead of the usual microswitches, with a normally closed logic.

## Wiring/pinout

Each button has 3 wires, black red and orange

- Daisychain all black wires to Arduino GND

- Daisychain all red wires to Arduino 3.3V or 5V

- Wire buttons 1 to 8 orange wires to Arduino gpio 2 to 9

## Behavior

- maimaiKeyboard maps buttons 1 to 8 to qwedcxza keys (ie. clockwise starting from top left)

- maimaiJoystick maps them to joystick button 1 to 8