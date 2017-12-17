#include <stdint.h>
#include <stdbool.h>



void radio_setup();
int radio_rssi();
void radio_rx(uint8_t channel);

uint8_t radio_get_chip_status();
void radio_test();
void radio_finetune();
void radio_test_clock(bool);

