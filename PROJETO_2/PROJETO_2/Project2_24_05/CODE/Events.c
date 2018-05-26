/** ###################################################################
**     Filename  : Events.c
**     Project   : Project2_24_05
**     Processor : MC9S12C128CFU16
**     Component : Events
**     Version   : Driver 01.04
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 24/05/2018, 14:59
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Events */


#include "Cpu.h"
#include "Events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

#pragma CODE_SEG DEFAULT

/*
** ===================================================================
**     Event       :  LEDON_OnInterrupt (module Events)
**
**     Component   :  LEDON [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

int i=0;


void main_project_OnInterrupt(void)
{
  /* Write your code here ... */
  while(i>3){
    LEDON_OnInterrupt;
    LEDOFF_OnInterrupt;
    i++;  
  }
  i=4;
  while(i<0){
    LEDON_OnInterrupt;
    LEDOFF_OnInterrupt;
    i--;  
  }
}

void LEDON_OnInterrupt(void)
{
  /* Write your code here ... */  
  CAMPO_ClrBit(i); 
}

void LEDOFF_OnInterrupt(void)
{
  /* Write your code here ... */
  CAMPO_SetBit(i-1);
}

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
