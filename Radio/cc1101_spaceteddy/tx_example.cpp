#include "cc1100_raspi.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>

// ----------------- Required globals for cc1100_raspi.cpp -----------------
int cc1100_freq_select   = 0;
int cc1100_mode_select   = 0;
int cc1100_channel_select = 0;

// ----------------- CC1100 variables -----------------
uint8_t Tx_fifo[FIFOBUFFER], Rx_fifo[FIFOBUFFER];
uint8_t My_addr = 1, Rx_addr, Pktlen;
uint8_t rx_addr, sender, lqi;
int8_t rssi_dbm;

uint8_t cc1100_debug = 1;
uint8_t tx_retries = 1;
uint8_t rx_demo_addr = 3;
int interval = 1000;

CC1100 cc1100;
uint32_t prev_millis_1s_timer = 0;

// ----------------- Custom Frequency -----------------
void set_custom_frequency(float freq_mhz) {
    uint32_t FREQ = (uint32_t)((freq_mhz * 1e6 / 26e6) * 65536);

    uint8_t freq2 = (FREQ >> 16) & 0xFF;
    uint8_t freq1 = (FREQ >> 8) & 0xFF;
    uint8_t freq0 = (FREQ) & 0xFF;

    cc1100.spi_write_register(0x0D, freq2); // FREQ2
    cc1100.spi_write_register(0x0E, freq1); // FREQ1
    cc1100.spi_write_register(0x0F, freq0); // FREQ0

    printf("Custom frequency set to %.2f MHz (regs=0x%02X 0x%02X 0x%02X)\n",
           freq_mhz, freq2, freq1, freq0);
}

// ----------------- Main -----------------
int main(int argc, char *argv[]) {
    printf("Raspberry Pi CC1101 TX Example\n");

    wiringPiSetup();
    cc1100.begin(My_addr);
    cc1100.sidle();

    set_custom_frequency(433.92);
    cc1100.set_output_power_level(0);
    cc1100.receive();

    cc1100.show_main_settings();
    cc1100.show_register_settings();

    for (;;) {
        delay(1);

        if (millis() - prev_millis_1s_timer >= interval) {
            Rx_addr = rx_demo_addr;

            uint32_t time_stamp = millis();
            Tx_fifo[3] = (uint8_t)(time_stamp >> 24);
            Tx_fifo[4] = (uint8_t)(time_stamp >> 16);
            Tx_fifo[5] = (uint8_t)(time_stamp >> 8);
            Tx_fifo[6] = (uint8_t)(time_stamp);

            Pktlen = 0x07;

            uint8_t res = cc1100.sent_packet(My_addr, Rx_addr, Tx_fifo, Pktlen, tx_retries);

            if (res == 1) {
                printf("Transmitted packet at %u ms\n", time_stamp);
            }

            prev_millis_1s_timer = millis();
        }
    }

    return 0;
}
