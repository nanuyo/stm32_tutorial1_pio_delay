################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../gpio/gpio_test.c 

OBJS += \
./gpio/gpio_test.o 

C_DEPS += \
./gpio/gpio_test.d 


# Each subdirectory must supply rules for building sources it contributes
gpio/%.o: ../gpio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F446RETx -DNUCLEO_F446RE -DSTM32F4 -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F446xx -I"D:/hjworkspace/stm32_tutorials_from_nanuyo.com/inc" -I"D:/hjworkspace/stm32_tutorials_from_nanuyo.com/CMSIS/core" -I"D:/hjworkspace/stm32_tutorials_from_nanuyo.com/CMSIS/device" -I"D:/hjworkspace/stm32_tutorials_from_nanuyo.com/StdPeriph_Driver/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


