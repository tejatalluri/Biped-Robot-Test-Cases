
// header file for adc
/********************************************************************************
Target system-AVR devlopment board s/n-118010
microcontroller: ATmega-8
clock: 12mhz

compiler win avr
******************************************************************************
ADC0 TO ADC6 - PC0 T0 PC6
********************************************************************************/


#ifndef _ADC_H_
#define _ADC_H_						

unsigned int adcdata,adcdata1;

 void adc_init()
 {
  ADCSRA=0X86;						//ADC enable, ADC interrupt enable, set prescaller to 64
  		
 }
 unsigned char getdata(unsigned char chno)	
  {
    ADMUX=0X60;						//right align the ADC result
    ADMUX|=chno;					//select the ADC channel
    ADCSRA|=0X40;					//start ADC convertion
     while((ADCSRA&0x40)==0x40);	
	return ADCH;
  }

#endif 