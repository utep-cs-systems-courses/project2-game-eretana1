#include <msp430.h>
#include "led.h"

void led_init()
{
  P1DIR |= LEDS;            // Set LEDS to be outputs 
  P1OUT &= ~LED_GREEN;      // Turn off green LED
  P1OUT |= LED_RED;         // Turn on red LED
}

void led_off()
{
  P1OUT &= ~LED_GREEN;
  P1OUT &= ~LED_RED;
}
