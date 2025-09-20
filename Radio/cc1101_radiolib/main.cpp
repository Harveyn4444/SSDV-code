/*
   RadioLib Non-Arduino Raspberry Pi Example

   This example shows how to use RadioLib without Arduino.
   In this case, a Raspberry Pi with WaveShare SX1302 LoRaWAN Hat
   using the lgpio library
   https://abyz.me.uk/lg/lgpio.html

   Can be used as a starting point to port RadioLib to any platform!
   See this API reference page for details on the RadioLib hardware abstraction
   https://jgromes.github.io/RadioLib/class_hal.html

   For full API reference, see the GitHub Pages
   https://jgromes.github.io/RadioLib/
*/

// include the library
#include <RadioLib.h>

// include the hardware abstraction layer
#include "hal/RPi/PiHal.h"

// create a new instance of the HAL class
// use SPI channel 1, because on Waveshare LoRaWAN Hat,
// the SX1261 CS is connected to CE1
//PiHal* hal = new PiHal(0);
PiHal* hal = new PiHal(0, 500000, 0);  // 500 kHz SPI0 CE0

// now we can create the radio module
// pinout corresponds to the Waveshare LoRaWAN Hat
// NSS pin:   7
// DIO1 pin:  17
// NRST pin:  22
// BUSY pin:  not connected
//SX1261 radio = new Module(hal, 7, 17, 22, RADIOLIB_NC);
			// HAL, CS, GDO0, GDO2, RST
CC1101 radio = new Module(hal, RADIOLIB_NC, 25, RADIOLIB_NC, RADIOLIB_NC); // Temp disable of CS (=8)as RPI "OWNS it"


// the entry point for the program
int main(int argc, char** argv) {
  // initialize just like with Arduino
  printf("[CC1101] Initializing ... ");
  int state = radio.begin(433.92);
  if (state != RADIOLIB_ERR_NONE) {
    printf("failed, code %d\n", state);
    return(1);
  }
  printf("success!\n");

  // loop forever
  int count = 0;
  for(;;) {
    // send a packet
    printf("[CC1101] Transmitting packet ... ");
    char str[64];
    sprintf(str, "Hello World! #%d", count++);
    state = radio.transmit(str);
    if(state == RADIOLIB_ERR_NONE) {
      // the packet was successfully transmitted
      printf("success!\n");

      // wait for a second before transmitting again
      // hal->delay(1000);

    } else {
      printf("failed, code %d\n", state);

    }
      hal->delay(1000);
  }

  return(0);
}
