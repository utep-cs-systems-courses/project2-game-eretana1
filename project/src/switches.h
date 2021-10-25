#ifndef switches_included
#define switches_included

#define SWS1 BIT0
#define SWS2 BIT1
#define SWS3 BIT2
#define SWS4 BIT3
#define SWITCHES (SWS1 | SWS2 | SWS3 | SWS4)

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed;

#endif
