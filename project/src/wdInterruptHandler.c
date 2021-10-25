#include <msp430.h>
#include "stateMachines.h"

int blink_count = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){      /* 250 interrupts/sec */
  state_advance(blink_count);
  if (++blink_count >= 250) blink_count = 0;
}
