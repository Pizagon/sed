#include "timer.h"

void retardo(int retardo){
   int i;
   T1CON=0x8000;
   TMR1 = 0;
   PR1 = 40000;
   i = 0;
   IFS0bits.T1IF = 0;
    while (i <= retardo){
        while(IFS0bits.T1IF == 0);
        IFS0bits.T1IF = 0; 
        i++;
   }
}
   
