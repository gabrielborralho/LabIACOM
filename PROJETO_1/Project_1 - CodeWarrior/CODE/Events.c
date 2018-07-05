/** ####  PROJETO 1 ###################################################
**
**     Filename  : Events.c
**     Project   : Project_01 - LAB. DE APLICA. COM MICROCOMPUTADORES
**     Professor : André Cavalcante
**     Processor : MC9S12C128CFU16 (HCS12)
**     Component : Events
**     Version   : Driver 01.04
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 06/05/2018, 09:24
**     Aluno     : Gabriel Borralho
**     Última Mod: 20/05/2018
**
**   OBSERVAÇÕES:
**   Todos os LEDs são iniciados em nível 1 (Apagados)
**   Interrupções são feitas a cada 250ms  
**
** ###################################################################*/

/* MODULE Events */
#include "Cpu.h"
#include "Events.h"
#include "math.h"
#pragma CODE_SEG DEFAULT

// VARIÁVEIS GLOBAIS
int unsigned vAC,vFR,anterior=0;
int unsigned setValue=1000; //Calibrar de acordo com o ambiente

//================ INICIO-CONVERSOR_AD =============================//
void AD1_OnEnd(void)
{
  int unsigned sensorValue,value,load,adj;

  AD1_GetChanValue(0x00,&sensorValue);
  load=sensorValue;  
  
  //----------------ACELERADOR/FREIO--------------------------------//
  if(!ACELERADOR_GetVal()){ //É verdadeiro quando o ACELERADOR é pressionado
      vAC++;
  }else if(!FREIO_GetVal()){//É verdadeiro quando o FREIO é pressionado
      LED4_ClrVal(); //Toda vez que o FREIO é pressionado o LED4 é ativado
      vFR++;
  }
  //--Modelo matemático para variação da distância a partir dos botões--//
  if(load>=vFR){ 
    value=load+vAC-vFR; 
  }
  
  //-------------- Remove Buffer do Teclado---------------------------//
  adj=0;
  while(adj+1<value){
     adj++;        
  } 
    
  //---Evita comportamentos inesperados quando os botões são ativados--//  
  if((value<0)||(value>=setValue)){
    value=sensorValue;
    vAC=0;
    vFR=0;
  }

 //------------------LED-GRADUAL---------------------------------------//
  if(value<=setValue){
    LED1_ClrVal(); // Acende o LED 1.
    if(value<((2*setValue)/3))
      LED2_ClrVal(); // Acende o LED 2.
    else
      LED2_SetVal(); // Apaga o LED 2.
    if(value<setValue/3)
      LED3_ClrVal(); // Acende o LED 3.
    else
      LED3_SetVal(); // Apaga o LED 3.
       
  //--------------LED-DE-APROXIMAÇÃO----------------------------------//    
    dX_OnInterrupt; //Chama a Interrupção de variação de distância
   
  //-------------- Apagar todos os LEDs ------------------------------//
   }else{
    LED1_SetVal();
    LED2_SetVal();
    LED3_SetVal();
  }
}
//==================== FIM-CONVERSOR_AD ==============================//


//======= INCIO-INTERRUPÇÃO DE VARIAÇÃO DA DISTÂNCIA==================//
void dX_OnInterrupt(void)
{
  int unsigned sensorValue,atual;
  AD1_GetChanValue(0x00,&sensorValue);
  
  atual=sensorValue;
      
  if(anterior<atual+5){
    LED4_SetVal();
  }else{
    LED4_ClrVal();
  }
  anterior=atual; //Atualiza o valor anterior  
}
//======= FIM-INTERRUPÇÃO DE VARIAÇÃO DA DISTÂNCIA==================//

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
