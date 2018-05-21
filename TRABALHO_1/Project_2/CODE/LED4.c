/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : LED4.c
**     Project   : Project_2
**     Processor : MC9S12C128CFU16
**     Component : BitIO
**     Version   : Component 02.075, Driver 03.15, CPU db: 2.87.410
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 20/05/2018, 21:42
**     Abstract  :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       23            |  PB7_ADDR7_DATA7
**             ----------------------------------------------------
**
**         Port name                   : B
**
**         Bit number (in port)        : 7
**         Bit mask of the port        : $0080
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 1
**         Initial pull option         : up
**
**         Port data register          : PORTB     [$0001]
**         Port control register       : DDRB      [$0003]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool LED4_GetVal(void);
**         PutVal - void LED4_PutVal(bool Val);
**         ClrVal - void LED4_ClrVal(void);
**         SetVal - void LED4_SetVal(void);
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE LED4. */

#include "LED4.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma DATA_SEG LED4_DATA             /* Select data segment "LED4_DATA" */
#pragma CODE_SEG LED4_CODE
#pragma CONST_SEG LED4_CONST           /* Constant section for this module */
/*
** ===================================================================
**     Method      :  LED4_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
/*
bool LED4_GetVal(void)

**  This method is implemented as a macro. See LED4.h file.  **
*/

/*
** ===================================================================
**     Method      :  LED4_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void LED4_PutVal(bool Val)
{
  if (Val) {
    setReg8Bits(PORTB, 0x80U);         /* BIT7=0x01U */
  } else { /* !Val */
    clrReg8Bits(PORTB, 0x80U);         /* BIT7=0x00U */
  } /* !Val */
}

/*
** ===================================================================
**     Method      :  LED4_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void LED4_ClrVal(void)

**  This method is implemented as a macro. See LED4.h file.  **
*/

/*
** ===================================================================
**     Method      :  LED4_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void LED4_SetVal(void)

**  This method is implemented as a macro. See LED4.h file.  **
*/


/* END LED4. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
