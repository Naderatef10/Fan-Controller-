################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lm35_sensor.c \
../adc.c \
../app.c \
../gpio.c \
../lcd.c \
../motor.c \
../pwm.c 

OBJS += \
./Lm35_sensor.o \
./adc.o \
./app.o \
./gpio.o \
./lcd.o \
./motor.o \
./pwm.o 

C_DEPS += \
./Lm35_sensor.d \
./adc.d \
./app.d \
./gpio.d \
./lcd.d \
./motor.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


