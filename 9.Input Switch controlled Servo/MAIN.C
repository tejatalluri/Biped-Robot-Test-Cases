
/*######################################################################
		Program to interface Servo motor using Header file
	****************************************************************************
	Target system-AVR devlopment board s/n-118010
	microcontroller: ATmega-8
	clock: 12mhz
	compiler WinAVR-20100110
	********************************************************************************/
	#include <avr/io.h>
	#include<util/delay.h>

	

	int main()
	 {
	 
	 DDRC=0x00; 
	 DDRB=0x0f;
	 PORTC=0x0f;
	 unsigned char i=0;
	 
	 while(1)
	   {
		if((PINC & 0x01) == 0x00)
		{
				  i++;	
				if(i>3)
				{	
					i=1;
				}
			while((PINC & 0x01)==0x00);
			}
			switch(i)
			{
			
			case 1:
			PORTB=0X01; // servo for 0 deg
			_delay_ms(1);
			PORTB=0X00;
			_delay_ms(19);
			break;
			case 2:
			PORTB=0X01; // servo for 90 deg
			_delay_ms(1.5);
			PORTB=0X00;
			_delay_ms(18.5);
			break;
			case 3:
			PORTB=0X01; // servo for 180 deg
			_delay_ms(2);
			PORTB=0X00;
			_delay_ms(18);
			break;
			}
			}
			}