# SSDV
This project aims to use a Raspberry Pi (Zero 2W) to capture and transmit an image.

This project is divided up into 2 main section `Code` and `Hardware`. Each of which will be contained within its own repo.

# Code
Again the code secton is split into sections. `Camera` code and `Radio` code. Currently the state of work is in the example and proof of concept stage, so the key milestones are currently to communicate with a radio module and take a photo using the Raspberry Pi.

## Radio
The current chosen radio is the `CC1101` which has a range of supported modulation types and can operate from 0 - 1 GHz.

## Camera 
The Pi will use the Raspberry Pi Camera v2.

## LEDs
The SSDV hardware has 3 LEDs for any user needs. The 3 GPIO pins connected to the LEDs are `16,20,21`. 
A blink example is included which blinks all 3 LEDs. As of now `LED3 - GPIO 21` is not working but is a hardware error rather than software.
Code is compiled with:
```
g++ -std=c++17 -o blink blink.cpp -lwiringPi
```

