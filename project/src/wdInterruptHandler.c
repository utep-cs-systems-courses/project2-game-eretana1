#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"
#include "led-assy.h"

int blink_count = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){      /* 250 interrupts/sec */
  if(sw1_state_down == 1){     // First switch activates state machine
    state_advance(blink_count);
    if (++blink_count >= 1000) blink_count = 0;
  }else if(sw2_state_down == 1){    // Second switch activates buzzer
    play_happyBirthday(blink_count);
    if(++blink_count >= 4000) blink_count = 0;
  }else if(sw3_state_down == 1){   // Third switch that activate assy code for leds
    alternate_leds(blink_count);
    if(++blink_count >= 750) blink_count = 0;
  }else if(sw4_state_down == 1){   // Fourth switch resets LEDs, and deactivates buzzer
    buzzer_off();
    led_off();
    blink_count = 0;
  }
}
