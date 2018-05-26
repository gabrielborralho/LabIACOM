/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Cpu.h
**     Project   : Project2_24_05
**     Processor : MC9S12C128CFU16
**     Component : MC9S12C32_80
**     Version   : Component 02.001, Driver 02.06, CPU db: 2.87.410
**     Datasheet : MC9S12C128 Rev 01.23 05/2007
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 24/05/2018, 15:34
**     Abstract  :
**         This component "MC9S12C32_80" implements properties, methods,
**         and events of the CPU.
**     Settings  :
**
**     Contents  :
**         EnableInt   - void Cpu_EnableInt(void);
**         DisableInt  - void Cpu_DisableInt(void);
**         SetWaitMode - void Cpu_SetWaitMode(void);
**         SetStopMode - void Cpu_SetStopMode(void);
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __Cpu
#define __Cpu

/* Active configuration define symbol */
#define PEcfg_C128CFU16 1U

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* MODULE Cpu. */


#pragma DATA_SEG DEFAULT               /* Select data segment "DEFAULT" */

#define CPU_BUS_CLK_HZ              0x001E8480UL /* Initial value of the bus clock frequency in Hz */

#define CPU_INSTR_CLK_HZ            0x001E8480UL /* Initial value of the instruction clock frequency in Hz */

#define CPU_EXT_CLK_HZ              0x003D0900UL /* Value of the main clock frequency (crystal or external clock) in Hz */

#define CPU_TICK_NS                 0xFAU /* CPU tick is a unit derived from the frequency of external clock source. If no external clock is enabled or available it is derived from the value of internal clock source. The value of this constant represents period of the clock source in ns. */

#define CPU_CORE_HCS12                 /* Specification of the core type of the selected cpu */
#define CPU_DERIVATIVE_MC9S12C128      /* Name of the selected cpu derivative */
#define CPU_PARTNUM_MC9S12C128CFU16    /* Part number of the selected cpu */

/* Global variables */

extern volatile byte CCR_reg;          /* Current CCR reegister */
/* Entry point routine(s) prototypes */

#pragma CODE_SEG __NEAR_SEG NON_BANKED
void _EntryPoint(void);
/*
** ===================================================================
**     Method      :  _EntryPoint (component MC9S12C32_80)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* Interrupt routine(s) prototypes */

/* Forward declaration of the default interrupt routine(s) */
__interrupt void Cpu_Interrupt(void);

#pragma CODE_SEG DEFAULT

#define Cpu_SetStopMode() \
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */\
  {__asm("ANDCC #0x7F"); __asm("STOP"); } \
  /*lint -restore Enable MISRA rule (1.1) checking. */
/*
** ===================================================================
**     Method      :  Cpu_SetStopMode (component MC9S12C32_80)
**
**     Description :
**         Set low power mode - Stop mode.
**         For more information about the stop mode see
**         documentation of this CPU.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define Cpu_SetWaitMode() \
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */\
  __asm("WAI") \
  /*lint -restore Enable MISRA rule (1.1) checking. */
/*
** ===================================================================
**     Method      :  Cpu_SetWaitMode (component MC9S12C32_80)
**
**     Description :
**         Set low power mode - Wait mode.
**         For more information about the wait mode see
**         documentation of this CPU.
**         Release from Wait mode: Reset or interrupt
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define   Cpu_DisableInt()  __DI()     /* Disable interrupts */
/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component MC9S12C32_80)
**
**     Description :
**         Disable maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define   Cpu_EnableInt()  __EI()      /* Enable interrupts */
/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component MC9S12C32_80)
**
**     Description :
**         Enable maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void PE_low_level_init(void);
/*
** ===================================================================
**     Method      :  PE_low_level_init (component MC9S12C32_80)
**
**     Description :
**         Initializes components and provides common register 
**         initialization. The method is called automatically as a part 
**         of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END Cpu. */

#endif /* ifndef __Cpu */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
