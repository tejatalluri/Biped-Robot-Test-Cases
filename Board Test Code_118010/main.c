/*Test code for mother board s/n 118010(ATMEGA8) 

*******************************************************************************
Target system-AVR devlopment board s/n-108010
microcontroller: ATmega-8
clock: 12mhz

compiler WinAVR-20100110

PORTS USED

	

LCD on PORTB

D4 PORTB.0
D5 PORTB.1 
D6 PORTB.2
D7 PORTB.3
RS PORTB.4
E  PORTB.5
XTAL1 PORTB.6
XTAL2 PORTB.7

Switches

S0 PortC0
RS Reset

LED 
	Active high
RED B0-PortB0
RED B1-PortB1
RED B2-PortB2
RED B3-PORTB3
green-Power on indicator usb
yellow-power on indicator DC jack

BUZZER

	Connected in active high mode
	PortC5
	J1-Buzzer enables

MOTOR DRIVERS

M2-PortB2
M3-PortB3
M4-PortD4
M5-PortD5
M6-PortD6
M7-PortD7

*********************************************************************************/
#include<avr/io.h>
#define F_CPU 12000000
#include <util/delay.h> 
#include "lcd118010.h"
#include "adc.h"
#define led PORTB
#define s0 (PINC&0x01)
unsigned char flag;
void checkswitch()
 {   
     ADCSRA=0X00;
     if(s0==0){while(s0==0);flag+=1;}
	 ADCSRA=0X87;
	
 }
 


int main()
 {
  DDRD=0xF0;
  PORTC=0x01;
  lcd_init();
  lcd_string("Technophilia");
  _delay_ms(1000);
  
  lcd_gotoxy(0,0);
  lcd_string("blinking LEDs ");
  lcd_gotoxy(1,0);
  lcd_string("press s0"); 
  flag=0;
   adc_init();
  while(1)
   {
	led=0x0F;
	_delay_ms(1000);
	led=0x00;
	_delay_ms(1000);
	 
	checkswitch(); 
	 
	while(flag==1)
	 {
	  lcd_gotoxy(0,0);
	  lcd_string("mov motor      ");
	  lcd_gotoxy(1,0);
	  lcd_string("press s0");
	 
      PORTD=0x50;
	  PORTB=0X04;
	  _delay_ms(1000);
	  PORTD=0xA0;
	  PORTB=0X08;
	  _delay_ms(1000);
	  
	  checkswitch();
	 }
	 
	/* while(flag==2)
	 {
	  lcd_gotoxy(0,0);
	  lcd_string("mov motor anticlockwise  ");
	  lcd_gotoxy(1,0);
	  lcd_string("press s2");
	  PORTD=0x50;
	  
	  checkswitch();
	 }*/
	 
	 while(flag==2)
	  {
	  PORTC=0x00;
	  lcd_gotoxy(0,0);
	  lcd_string("ADC ");
	  lcd_showvalue(getdata(0));
	  lcd_string(",");
	  lcd_showvalue(getdata(1));
	  lcd_string(",");
	  lcd_showvalue(getdata(2));
	  lcd_gotoxy(1,0);
	  lcd_string("press s0");
	  PORTC=0x0F;
	  checkswitch();
	   
	  }
   }
  }