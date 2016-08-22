################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

OBJS += \
./startup/startup_stm32.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo %cd%
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"D:/hjworkspace/stm32_tutorials_from_nanuyo.com/inc" -I"D:/hjworkspace/stm32_tutorials_from_nanuyo.com/CMSIS/core" -I"D:/hjworkspace/stm32_tutorials_from_nanuyo.com/CMSIS/device" -I"D:/hjworkspace/stm32_tutorials_from_nanuyo.com/StdPeriph_Driver/inc" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


