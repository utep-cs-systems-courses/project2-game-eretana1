#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "led.h"

char sw1_state_down, sw2_state_down,
  sw3_state_down, sw4_state_down, switch_state_changed; /* effectively boolean */

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;

  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */
  return p2val;
}

void
switch_init()/* setup switch */
{
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE |= SWITCHES;/* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */
  switch_update_interrupt_sense();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  
  sw1_state_down = (p2val & SWS1) ? 0 : 1; /* 0 when SW1 is up */
  sw2_state_down = (p2val & SWS2) ? 0 : 1; /* 0 when SW2 is up */
  sw3_state_down = (p2val & SWS3) ? 0 : 1; /* 0 when SW3 is up */
  sw4_state_down = (p2val & SWS4) ? 0 : 1; /* 0 when SW4 is up */
}

/* Switch on P2 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */
    switch_interrupt_handler();/* single handler for all switches */
  }
}
