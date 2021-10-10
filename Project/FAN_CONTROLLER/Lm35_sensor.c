#include "lm35_sensor.h"
#include "adc.h"

uint8 LM35_GetTemperature(){
uint16 digital_value;
uint8 temp;
digital_value =	ADC_readChannel(LM35_PIN_NUMBER);

temp=(uint8 )( ((uint32)digital_value*ADC_REFERANCE_VOLTAGE*LM35_MAX_VALUE)/(LM35_MAX_VOLT*ADC_MAX_VALUE) );
/* we casted uint32 because overflow will occur in the numerator then we cast back to uint8*/
/*the hash defines of the adc is in the adc.h not the sensors headerfile*/

return temp;


}
