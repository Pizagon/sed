    .text
    .global _retardo
_retardo:
    ;
  MOV #0x8000, T1CON //timer on sin preescaladao
  MOV #0, TMR1 //Cuenta a 0
  MOV #40000, PR1 //Final de cuenta a 40000
  MOV #0, IFS0.bits.T1IF //Interrupcion a cero
  MOV #0, W14 //i

  CP W14,W1 //Supongo que el valor de retardo se guarda en el W1 en el main
  BRA LEU, fin // while(i<=retardo)
  CP IFS0.bits.T1IF, #0
  BRA  Z, fin // while(IFS0.bits.T1IF==0)
  BRA while
  MOV #0, IFS0.bits.T1IF //IFS0.bits.T1IF=0;
  INC W14 //i++
  BRA while
     return
    .end

/*#include "timer.h"
/*Contador de 1 ms que se ejecuta retardo veces */
;void retardo(int retardo){
;   int i;
;   T1CON=0x8000;
;   TMR1 = 0;
;   PR1 = 40000;
;   i = 0;
;   IFS0bits.T1IF = 0;
;    while (i <= retardo){
;        while(IFS0bits.T1IF == 0);
;        IFS0bits.T1IF = 0; 
;        i++;
;   }
;}
   
