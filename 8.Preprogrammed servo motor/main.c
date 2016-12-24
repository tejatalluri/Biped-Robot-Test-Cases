/*######################################################################
		Program to interface Servo motor using Header file
	
	Target system-AVR devlopment board s/n-118010
	microcontroller: ATmega-8
	clock: 12mhz
	compiler WinAVR-20100110
	********************************************************************************/

#include <avr/io.h>
#include<util/delay.h>

	

	int main()
	 {
	 
	 DDRB=0x01; //Motor is connected AT PORT B.0
	 
	 while(1)
	   {
			PORTB=0X01; // high pulse of 1 ms for 0 deg.
			_delay_ms(1);
			PORTB=0X00; //low pulse of 19 ms
			_delay_ms(19);
			  
			  _delay_ms(1000);
			  
			
			
			
			
			PORTB=0X01; // high pulse of 1 ms for 90 deg.
			_delay_us(1500);
			PORTB=0X00;
			_delay_us(18500);//low pulse of 18.5 ms
			
			_delay_ms(1000);
			
			
			
			PORTB=0X01;// high pulse of 2 ms for 180 deg.
			_delay_ms(2);
			PORTB=0X00;
			_delay_ms(18);//low pulse of 18.5 ms
			
			_delay_ms(1000);
			
			
			
			}
			}
			