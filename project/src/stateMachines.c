#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

// global states to control blinking
int intensity_state = 0;
int fast_state = 0;
int blink_state = 0;

// State that blinks the LED every 125/250 == half a second
char on_off_state(int blink_count)
{
  if(blink_count % 125 == 0){
    blink_state ^= 1;
  }
  return blink_state;
}

// State that determines the current light intensity state: e.g. 0,1,2,3,0,1....
char light_intensity_state(int blink_count)
{
  if(blink_count % 250 == 0){
    intensity_state = (intensity_state % 4) + 1;
  }
  return intensity_state;
}

// Function to set light intesity to 25%
void light_25(int state)
{
  switch(state){
  case 0:
  case 1:
  case 2: 
    P1OUT &= ~LED_GREEN;
    P1OUT |= LED_RED;
    break;
  case 3:
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
  default:
    break;
  }
}

// Function to set light intesity to 50%
void light_50(int state)
{
  switch(state){
  case 0:
  case 1:
    P1OUT &= ~LED_GREEN;
    P1OUT |= LED_RED;
    break;
  case 2: 
  case 3:
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
  default:
    break;
  }
}

// Function to set light intesity to 75%
void light_75(int state)
{
  switch(state){
  case 0:
    P1OUT &= ~LED_GREEN;
    P1OUT |= LED_RED;
    break;
  case 1:
  case 2: 
  case 3:
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
  default:
    break;
  }
}

// Function to set light intesity to 100%
void light_on()
{
  P1OUT |= LED_GREEN;
  P1OUT &= ~LED_RED;
}

char fast_blink_state()
{
  fast_state = (fast_state + 1) % 4;
  switch(intensity_state){
  case 1: light_on(fast_state); break;
  case 2: light_75(fast_state); break;
  case 3: light_50(fast_state); break;
  case 4: light_25(fast_state); break;
  default: break;
  }
}

void state_advance(int blink_count)   /* update the current state */
{
  on_off_state(blink_count);

  if(blink_state == 0){
    P1OUT &= ~LED_GREEN; // Turn off led
    P1OUT |= LED_RED;
  }else{
    light_intensity_state(blink_count);
    fast_blink_state();
  } 
}
