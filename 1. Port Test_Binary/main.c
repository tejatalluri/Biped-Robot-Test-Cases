
/************************************************* Program Title ******************

* Program to send binary data (00001010) to PORT B & Glow LED1 & LED3

Target System:......AVR Devlopment Board S/N-118010
Microcontroller:....ATmega-8
Clock:..............12mhz
Compiler Used:...........WinAVR-20100110

************************************************** Connection Details *************

LED-PORTB

***************************************************Program ***********************/

#include<avr/io.h>				//basic header file for avr microcontrollers

int main(void)
{
	
	DDRB=0b00001111;			//data direction declaration of PORTB lower pins as output.	
	PORTB=0b00001010;			//sending binary data (00001010) to PORTB
	
	while(1)
	{
		
	}
}
