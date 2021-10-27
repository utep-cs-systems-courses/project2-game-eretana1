#include <msp430.h>
#include "led.h"

void alternate_leds(int blink_count)  /* 1 sec = 250 interrupts */
{
  if(blink_count >= 500){          // Enable both lights at 2 seconds
    P1OUT |= LED_RED;
    P1OUT |= LED_GREEN;
  }else if(blink_count >= 250){    // Enable red light every second
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;
  }else if(blink_count >= 125){    // Enable green light every half/sec 
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
  }
}
