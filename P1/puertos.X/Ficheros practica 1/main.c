#include "config.h"


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



/*void main(void){
        // InicializarReloj();
        //RemapeaPerifericos();
    P11
     PORTB=0xEFFF;
    TRISB=0x0FFF;
    P12int i = 0;
	PORTB=0xEFFF;
    TRISB=0x0FFF;
    
    while(1)
    i=i+1;
   
       // return 0;

}
*/
int main(void){
    
    //Enciende led Rb15 y Rb14,
    //al pulsar el pulsador SW1 se apagan los LEDs
    //Si ponemos el bit 15 como entrada, no harÌa nada porque est· conectado a un LED por lo tanto no 
    //cambiarÌa el valor del bit.
    /*PORTB=0x3FFF;
    TRISB=0x0FFF;
    while(1);
    return 0;*/
    
    /*
    //Programa para encender LED RB14
    PORTB=0xBFFF;
    TRISB=0x0FFF;
    while(1);
    return 0;
    */
    
    /* 
     Para encender el RB15 y el RB14 se usa el programa del principio
     */
   /* int temp, a,b;
    ADPCFG = 0xFFFF;  //encender el led RB12 con pulsadorRB2
    PORTB=0x0FFF;
    TRISB=0x0FFF;
    while(1){
        b = PORTB;
        a = PORTB;
        
        temp = PORTB & 0x0004;
        a &= ~0x1000;
        a |= temp << 10;
        
        PORTB = a;
        }   
    return 0;*/

/*    int temp, a,b;
    ADPCFG = 0xFFFF;  //encender el led RB13 con pulsadorRB2 
    PORTB=0x0FFF;
    TRISB=0x0FFF;
    while(1){
        b = PORTB;
        a = PORTB;
        
        temp = b & 0x0004;
        a &= ~0x2000;
        a |= temp << 11;
        
        PORTB = a;
        }   
    return 0;*/
    /*Programa que cuente los cambios de estado del pulsador y los muestre en
     LEDs.
     */
      /*int temp, a,b,cambio,aux,temp2;
    //ADPCFG = 0xFFFF;  //encender el led RB13 con pulsadorRB2 
    PORTB=0x0FFF;
    TRISB=0x0FFF;
    cambio=0x0000; //inicio variable de guardado de los cambios de estado a 0
    while(1){
        b = PORTB;
        a = PORTB;
        temp = (b & 0x0004)>>3;//leo pulsador y lo pongo en el bit menos significativo
        temp2 = (b & 0x0004)>>3;//leo pulsador y lo pongo en el bit menos significativo
        while(temp==0){
            temp = (b & 0x0004)>>3;
            if(temp==1){
                if (cambio<=15)//N˙mero m·ximo que se puede mostrar con 4 LEDs es 15
                cambio++;
                else
                cambio=0;//Si detecta mas cambios de estado de 15 que se ponga a 0 ya que no se pueden mostrar cambios.
            }
        }
        while(temp2==1){
            temp2 = (b & 0x0004)>>3;
            if(temp2==0){//Mantengo pulsado: 1+1. Sin pulsar 0+0
                if (cambio<=15)//N˙mero m·ximo que se puede mostrar con 4 LEDs es 15
                cambio++;
                else
                cambio=0;//Si detecta mas cambios de estado de 15 que se ponga a 0 ya que no se pueden mostrar cambios.
            }
        }
        aux=cambio<<12;//variable auxiliar para guardar los cambios.
        a &= ~0xf000; //Se ponen los bits de los 4 LEDs del portb a 0.
        a |= aux; //Se copia los cambios en los LEDs
        
        PORTB = a; //Se escribe en el puerto.
        }   
    return 0;*/
    
    /*int temp, a,b,cambio,aux,temp2;
    ADPCFG = 0xFFFF;  //encender el led RB13 con pulsadorRB2 
    PORTB=0x0FFF;
    TRISB=0x0FFF;
    cambio=0x0000; //inicio variable de guardado de los cambios de estado a 0
    a=PORTB;
    temp = (a & 0x0004)>>2;//leo pulsador y lo pongo en el bit menos significativo
    while(1){

        temp2=temp;
        b = PORTB;
        temp=(b & 0x0004)>>2;
        if(temp!=temp2){
            if(cambio<=15)
                cambio++;
            else 
                cambio=0;
        }
        aux=cambio<<12;
        a&=0x0FFF;
        a|=aux;
        PORTB=a;
    }
    return 0;*/
	/*int temp[5];
	int  b, i, cambio;
	
	ADPCFG = 0xFFFF;
	PORTB = 0x0FFF;
	TRISB = 0x0FFF;

	b = PORTB;
	cambio = PORTB;
	temp[1] = 0xEFFF;//1110
	temp[2] = 0xDFFF;//1101
	temp[3] = 0xBFFF;//1011
	temp[4] = 0x7FFF;//0111
	
	while (1) {
		i = 4;
		while(i > 0) {
            b = PORTB;
            PORTB = temp[i];
			if((cambio != b) && (cambio &= 4)){ //Suponiendo que pulsador mete 0
				i--;
                PORTB = temp[i];
			}
			cambio = b;
		}
	}
    return 0;*/
   /* int temp[16];
	int b, cambio, i;
		
	ADPCFG = 0xFFFF;
	PORTB = 0xFFFF;
	TRISB = 0x0FFF;
	
	cambio = PORTB;
	temp[1] = 0xFFFF;//1111
	temp[2] = 0xEFFF;//1110
	temp[3] = 0xDFFF;//1101
	temp[4] = 0xCFFF;//1100
	temp[5] = 0xBFFF;//1011
	temp[6] = 0xAFFF;//1010
	temp[7] = 0x9FFF;//1001
	temp[8] = 0x8FFF;//1000
	temp[9] = 0x7FFF;//0111
	temp[10] = 0x6FFF;//0110
	temp[11] = 0x5FFF;//0101
	temp[12] = 0x4FFF;//0100
	temp[13] = 0x3FFF;//0011
	temp[14] = 0x2FFF;//0010
	temp[15] = 0x1FFF;//0001
	temp[16] = 0x0FFF;//0000
	while (1) {
		i = 1;
		while(i < 17) {
            b = PORTB;
            PORTB = temp[i];
			if((cambio != b) && (cambio &= 4)){ //Suponiendo que pulsador mete 0
				i++;
                PORTB = temp[i];
			}
			cambio = b;
		}
    }
	*/
    
    int portd_act,portd_ant;
    
    ADPCFG = 0xFFFF;
    PORTB=0xEFFF;   
    TRISB=0x0FFF;
    portd_act=PORTB & 2;
    while(1){
        portd_ant=portd_act;
        portd_act= PORTB &4;
        if((portd_ant !=portd_act) && (portd_ant &=4)){//Se comprueba que se pulsa el bit 4
            PORTB=((PORTB | 0x0F00) << 1);//Se pone la m·scara para que se desplace un 1 a los LEDs
            if((PORTB & 0xF000) == 0xF000){
                PORTB=0xEFFF;
            }
        }
    }
    return 0;
     
}



