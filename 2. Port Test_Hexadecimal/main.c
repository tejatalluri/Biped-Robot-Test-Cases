
/************************************************* Program Title ******************

/*Program to send hexadecimal data to PORTB & Glow LED1 & LED3

Target System:......AVR Devlopment Board S/N-118010
Microcontroller:....ATmega-8
Clock:..............12mhz
Compiler Used:...........WinAVR-20100110

************************************************** Connection Details *************

LED-PORTB

***************************************************Program ***********************/


#include<avr/io.h>		//basic header file for avr micro controllers

int main(void)
{
	
	DDRB=0x0F;			//Data direction declaration of PORTB lower bits as output port.	
	PORTB=0x0A;			//sending HEX data to PORTB
	
	while(1)
	{
		
	}
}
