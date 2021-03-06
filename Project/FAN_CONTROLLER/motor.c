#include "motor.h"
#include "gpio.h"
#include "pwm.h"

void DcMotor_Init(void){

	GPIO_setupPinDirection( MOTOR_PORT,INPUT1_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection( MOTOR_PORT,INPUT2_PIN,PIN_OUTPUT);

	GPIO_writePin(MOTOR_PORT,INPUT1_PIN,LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT,INPUT2_PIN,LOGIC_LOW);

}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	if(state== OFF){
		GPIO_writePin(MOTOR_PORT,INPUT1_PIN,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT,INPUT2_PIN,LOGIC_LOW);

	}

	else if(state == CW){
		Timer0_PWM_Init(speed);
		GPIO_writePin(MOTOR_PORT,INPUT1_PIN,LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT,INPUT2_PIN,LOGIC_LOW);

	}

	else if(state == ACW){
		Timer0_PWM_Init(speed);
		GPIO_writePin(MOTOR_PORT,INPUT1_PIN,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT,INPUT2_PIN,LOGIC_HIGH);

	}



}
