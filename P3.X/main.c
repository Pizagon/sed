#include "config.h"
#include "timer.h"

// ----------------------------------------------------------------------------------
// ----------------------------- BITS DE CONFIGURACI?N ------------------------------
// ----------------------------------------------------------------------------------

// 1. Eliminar el segmento de arranque flash
// 2. Permitir la escritura del segmento de arranque flash
_FBS(BSS_NO_BOOT_CODE & BWRP_WRPROTECT_OFF);

// 1. No proteger la memoria de programa contra escritura
// 2. No proteger el c€digo
_FGS(GWRP_OFF & GCP_OFF);

// 1. Utilizar el oscilador interno (FRC) en el arranque
// 2. Arrancar directamente con el oscilador seleccionado
_FOSCSEL(FNOSC_FRC & IESO_OFF);

// 1. Permitir la conmutaci€n del reloj y deshabilitar la monitorizaci€n de fallos
// 2. Desactivar el oscilador primario
// 3. Utilizar el oscilador secundario como entrada y salida digital
// 4. Permitir m?ltiples remapeos de los pines
_FOSC(FCKSM_CSECMD & POSCMD_NONE & OSCIOFNC_ON & IOL1WAY_OFF);

// 1. Permitir la deshabilitaci€n del watchdog timer
//    poniendo a 0 el bit SWDTEN del registro RCON
_FWDT(FWDTEN_OFF);

// 1. Esperar 128 ms y resetear el microcontrolador al enchufar la alimentaci€n
// 2. Controlar los pines de PWM desde el registro PORT al arrancar
// 3. Los pines PWM high est∑n activos a nivel alto
// 4. Los pines PWM low est∑n activos a nivel alto
// 5. Utilizar los pines est∑ndar (SDA1 y SCL1) para el I2C
_FPOR(FPWRT_PWR128 & PWMPIN_ON & HPOL_ON & LPOL_ON & ALTI2C_OFF);

// 1. Programar y depurar a trav»s de los pines PGC1 y PGD1
// 2. Desactivar el interfaz para JTAG
_FICD(ICS_PGD1 & JTAGEN_OFF);



/*int main(void){
   InicializarReloj();
   RemapeaPerifericos();
    PORTB=0xEFFF;
    TRISB=0X0FFF;
    TMR1=0;
    PR1=0xFFFF;
    IFS0bits.T1IF=0;
    T1CON=0x8030;
    while(1){
        PORTB=PORTB ^ 0x1000;
        while(IFS0bits.T1IF==0);
        IFS0bits.T1IF=0;
    }
    return 0;
}*/

/*int main(void){
  
    PORTB=0xEFFF;
    TRISB=0X0FFF;
    while(1){
        PORTB=PORTB ^ 0x1000;
        retardo(1000);
    }
    return 0;
}*/
/*int main (void){
 int i,j,k;   
 InicializarReloj();
 RemapeaPerifericos();
    PORTB = 0xFFFF;
    TRISB = 0x0FFF;
    i=0;
    j=0;
    k=0;
    while(1){
        retardo(100);
        i++;
        k++;
        if (k == 2){
            PORTB ^= 0x2000;
            k=0;
        }
        if((i == 5) || (i == 15)){
            PORTB ^= 0x1000;
            if (i == 0x000F){
                i = 0;
            }
        }
    } 
            
}*/
int main (void){
 int i,j,k, l,  x;
 int T1_on,T1_off,T3_on,T3_off,T4_on,T4_off;
 ADPCFG = 0xFFFF;
 InicializarReloj();
 RemapeaPerifericos();
    PORTB = 0xFFFF;
    TRISB = 0x0FFF;
    i=0;
    j=0;
    k=0;
    x = 0;
    while(1){
        retardo(100);
        i++;
        j++;
        k++;
        l++;
        x = PORTB & 4;
        if (x == 4) {
            T1_on=10;
            T1_off=5;
            //T2_on=2;
            //T2_off=2;
            T3_on=10;
            T3_off=20;
            T4_on=15;
            T4_off=30;
        }
        if (x == 0) {
            T1_off=10;
            T1_on=5;
            //T2_off=2;
            //T2_on=2;
            T3_off=10;
            T3_on=20;
            T4_off=15;
            T4_on=30;
        }
        if (k == 2){
            PORTB ^= 0x2000;
            k=0;
        }
        if((i == T1_on) || (i == T1_off+T1_on)) {
            PORTB ^= 0x1000;
            if (i == T1_off+T1_on){
                i = 0;
            }
        }
        if((j == T3_on) || (j == T3_off+T3_on)){
            PORTB ^= 0x4000;
            if(j == T3_off+T3_on){
                j = 0;
            } 
        }
        if ((l == T4_on) || (l == T4_off+T4_on)){
            PORTB ^= 0x8000;
            if (l == T4_off+T4_on){
                l = 0;
            }
        }
    } 
            
}