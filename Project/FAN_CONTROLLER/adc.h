
#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"

#define ADC_REFERANCE_VOLTAGE 2.56
#define ADC_NUMBER_OF_BITS 10
#define ADC_MAX_VALUE 1023

/* Type definitions*/

/*enum to determine the value of vref (the type of it's connection)*/

typedef enum{

	AREF, AVCC,INTERNAL_REF_VOLT = 3

}ADC_ReferenceVolatge;


/*enum to determine the value of prescaling of the frequency of the ADC*/

typedef enum{

	F_CPU_2=0,F_CPU_4=2,F_CPU_8=3,F_CPU_16=4,F_CPU_32=5,F_CPU_64=6,F_CPU_128=7

}ADC_Prescaler;

/*Configuration structure of the ADC, that we will use to dynamically configure the adc during runtime*/

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*Function declarations*/


/*function that initalizes the ADC driver*/
void ADC_init(const ADC_ConfigType*);

/*function that reads the ADC channel */
uint16 ADC_readChannel(uint8 channel_number);



#endif /* ADC_H_ */
