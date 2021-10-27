## Description
This directory contains the program that utilizes the MSP430 switches, LED blinking and dimming, and the buzzer.

## Modularization
This program is split up into different classes + functions:
- State machine
- Buzzer
- Interrupts
- LEDs
- Blink state machine for C and ASSY
- Switches
- The main function.

### Button Mapping
Each switch is mapped to a specific function, which utilizes interrupts to read the press and release of each button. **Note: each function is executed while the button is pressed.**

Button      | Description
----------- | ---------------
Switch S1   | State machine for the LEDs that flashes and dims green and red LEDs. The green LED will decrease light intensity in 25% decrements, and the red light will act as the inverse of the green led.
Switch S2   | Enables the buzzer and plays the happy birthday song.
Switch S3   | Flashes the LEDs in alternating pattern followed by a final joint flash of both LEDS. Calling `make load` will compile code in C, 'make load-s' will compile code in ASSY.
Switch S4   | Reset button for any switch. (Disables buzzer and turns off LEDs).

## How to Use

The Makefile in this direcory contains rules to run the Makefile in the project directory. Use **make** in this directory to build the project and timer library. Once the programs are built, you can load the program onto the MSP430 by changing into the corresponding src directory and using **make load** or **make load-s**.

