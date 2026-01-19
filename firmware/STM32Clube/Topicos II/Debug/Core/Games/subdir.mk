################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Games/snake.c 

OBJS += \
./Core/Games/snake.o 

C_DEPS += \
./Core/Games/snake.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Games/%.o Core/Games/%.su Core/Games/%.cyclo: ../Core/Games/%.c Core/Games/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/Menu" -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/Drivers" -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/Drivers" -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/Games" -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/System" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Games

clean-Core-2f-Games:
	-$(RM) ./Core/Games/snake.cyclo ./Core/Games/snake.d ./Core/Games/snake.o ./Core/Games/snake.su

.PHONY: clean-Core-2f-Games

