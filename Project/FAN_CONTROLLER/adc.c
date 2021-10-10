#include "adc.h"
#include <avr/io.h>
#include "common_macros.h"


/*ADC_init function to initalize the adc driver
 it takes a pointer to structure (ADC_ConfigType) to configure the driver
 */
void ADC_init(const ADC_ConfigType* Config_ptr){
	ADMUX = (ADMUX & 0x3F)| ((Config_ptr->ref_volt)<<6);
	ADCSRA = (ADCSRA & 0xF8) | (Config_ptr->prescaler);
	ADCSRA |=(1<<ADEN);
}

/* ADC_readChannel function to read the the digital value resulted From the ADC operation
 it takes channel_number as input to choose which adc channel the adc unit will convert
 */

uint16 ADC_readChannel(uint8 channel_number){

	ADMUX = (ADMUX & 0xE0) | channel_number;
	ADCSRA |= (1<< ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	ADCSRA |= (1<<ADIF);
	return ADC;



}
