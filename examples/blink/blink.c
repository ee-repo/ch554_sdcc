// Blink an LED connected to pin 1.7

#include <stdint.h>

#include "../../public/ch554.h"
#include "../../public/debug.h"

#define LED_PIN 7
SBIT(LED, 0x90, LED_PIN);

void main() {
    uint16_t i;

    CfgFsys();

    // Configure pin 1.6 as GPIO output
    P1_DIR_PU &= 0x0C;
    P1_MOD_OC = P1_MOD_OC & ~(1<<LED_PIN);
    P1_DIR_PU = P1_DIR_PU |	(1<<LED_PIN);

    while (1) {
        for(i = 0; i < 65535; i++) {}
        LED = !LED;
    }
}
