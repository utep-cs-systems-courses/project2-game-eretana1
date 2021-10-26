#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init()
{
  /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
  */

  timerAUpmode();/* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;/* one half cycle */
}

void buzzer_off()
{
  buzzer_set_period(0);
}

// Function that utilizes the buzzer to play the happy birthday song.
void play_happyBirthday(int seconds)
{
  seconds++;
  if(seconds >= 4000){
    seconds = 0;
  }else if(seconds >= 3750){
    buzzer_set_period(0);
  }else if(seconds > 3550){
    buzzer_set_period(3000);
  }else if(seconds >= 3400){
    buzzer_set_period(2700);
  }else if(seconds >= 3250){
    buzzer_set_period(3000);
  }else if(seconds > 3100){
    buzzer_set_period(2400);
  }else if(seconds >= 3050){
    buzzer_set_period(2300);
  }else if(seconds >= 3000){
    buzzer_set_period(0);
  }else if(seconds >= 2950){
    buzzer_set_period(2300);
  }else if(seconds >= 2850){ // third part
    buzzer_set_period(0);
  }else if(seconds >= 2700){
    buzzer_set_period(3600);
  }else if(seconds >= 2550){
    buzzer_set_period(3200);
  }else if(seconds >= 2400){
    buzzer_set_period(3000);
  }else if(seconds >= 2250){
    buzzer_set_period(2425);
  }else if(seconds >= 2100){
    buzzer_set_period(2000);
  }else if(seconds >= 2050){
    buzzer_set_period(4000);
  }else if(seconds >= 2000){
    buzzer_set_period(0);
  }else if(seconds >= 1950){
    buzzer_set_period(4000);
  }else if(seconds >= 1750){ // second part
    buzzer_set_period(0);
  }else if(seconds >= 1600){
    buzzer_set_period(3000);
  }else if(seconds >= 1450){
    buzzer_set_period(2700);
  }else if(seconds >= 1300){
    buzzer_set_period(4000);
  }else if(seconds >= 1150){
    buzzer_set_period(3600);
  }else if(seconds >= 1100){
    buzzer_set_period(4000);
  }else if(seconds >= 1050){
    buzzer_set_period(0);
  }else if(seconds >= 1000){
    buzzer_set_period(4000);
  }else if(seconds >= 850){
    buzzer_set_period(0);
  }else if(seconds >= 600){ // first part
    buzzer_set_period(3200);
  }else if(seconds >= 450){
    buzzer_set_period(3000);
  }else if(seconds >= 300){
    buzzer_set_period(4000);
  }else if(seconds >= 150){
    buzzer_set_period(3600);
  }else if(seconds >= 100){
    buzzer_set_period(4000);
  }else if(seconds >= 50){
    buzzer_set_period(0);
  }else if(seconds >= 0){
    buzzer_set_period(4000);
  }
}
