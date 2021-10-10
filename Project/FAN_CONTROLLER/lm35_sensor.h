/*
 * lm35_sensor.h
 *
 *  Created on: Oct 9, 2021
 *      Author: nader atef
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

#define LM35_PIN_NUMBER 2

#define LM35_MAX_VOLT 1.5
#define LM35_MAX_VALUE 150




/*function to calculate the temperature from the equivelant digital value using ADC*/
uint8 LM35_GetTemperature();

#endif /* LM35_SENSOR_H_ */
