/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : main_project.h
**     Project   : Project2_24_05
**     Processor : MC9S12C128CFU16
**     Component : TimerInt
**     Version   : Component 02.159, Driver 01.20, CPU db: 2.87.410
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 24/05/2018, 16:58
**     Abstract  :
**         This component "TimerInt" implements a periodic interrupt.
**         When the component and its events are enabled, the "OnInterrupt"
**         event is called periodically with the period that you specify.
**         TimerInt supports also changing the period in runtime.
**         The source of periodic interrupt can be timer compare or reload
**         register or timer-overflow interrupt (of free running counter).
**     Settings  :
**         Timer name                  : TIM_Counter (16-bit)
**         Compare name                : TC0
**         Counter shared              : Yes
**
**         High speed mode
**             Prescaler               : divide-by-8
**             Clock                   : 250000 Hz
**           Initial period/frequency
**             Xtal ticks              : 1000000
**             microseconds            : 250000
**             milliseconds            : 250
**             seconds (real)          : 0.25
**             Hz                      : 4
**
**         Runtime setting             : none
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Counter                : TCNT      [$0044]
**              Mode                   : TIOS      [$0040]
**              Run                    : TSCR1     [$0046]
**              Prescaler              : TSCR2     [$004D]
**
**         Compare registers
**              Compare                : TC0       [$0050]
**
**         Flip-flop registers
**              Mode                   : TCTL2     [$0049]
**     Contents  :
**         Enable - byte main_project_Enable(void);
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __main_project
#define __main_project

/* MODULE main_project. */

#include "Cpu.h"

#pragma CODE_SEG main_project_CODE


byte main_project_Enable(void);
/*
** ===================================================================
**     Method      :  main_project_Enable (component TimerInt)
**
**     Description :
**         This method enables the component - it starts the timer.
**         Events may be generated (<DisableEvent>/<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void main_project_Interrupt(void);
/*
** ===================================================================
**     Method      :  main_project_Interrupt (component TimerInt)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG DEFAULT

/* END main_project. */

#endif /* ifndef __main_project */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/