#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "motor.h"

int main(){
	/*variable declarations and drivers configurations*/
	uint8 sensor_temp=0;
	ADC_ConfigType Sensor={INTERNAL_REF_VOLT,F_CPU_8};

	/*Drivers initilizations*/
	DcMotor_Init();
	LCD_init();
	ADC_init(&Sensor);

	/* app code*/
	LCD_moveCursor(0,3);
	LCD_displayString("FAN IS ");
	LCD_moveCursor(1,3);
	LCD_displayString("Temp =   C ");

	/*Application*/
	while(1){

		LCD_moveCursor(1,10);
		sensor_temp= LM35_GetTemperature();
		if(sensor_temp>=100){
		LCD_intgerToString(sensor_temp);
		}
		else{
			LCD_intgerToString(sensor_temp);
			LCD_displayCharacter(' ');
		}
		if(sensor_temp < 30){
			DcMotor_Rotate(OFF,0);
			LCD_moveCursor(0,10);
			LCD_displayString("OFF");

		}
		else if(sensor_temp >=30 && sensor_temp <60){
			DcMotor_Rotate(CW,25);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');

		}

		else if(sensor_temp>=60 && sensor_temp <90){
			DcMotor_Rotate(CW,50);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');

		}
		else if(sensor_temp>=90 && sensor_temp <120){

			DcMotor_Rotate(CW,75);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');


		}
		else if(sensor_temp>=120){

			DcMotor_Rotate(CW,100);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}


	}

}
