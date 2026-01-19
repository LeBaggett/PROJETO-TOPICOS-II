################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/System/system.c 

OBJS += \
./Core/System/system.o 

C_DEPS += \
./Core/System/system.d 


# Each subdirectory must supply rules for building sources it contributes
Core/System/%.o Core/System/%.su Core/System/%.cyclo: ../Core/System/%.c Core/System/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/Menu" -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/Drivers" -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/Drivers" -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/Games" -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/System" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-System

clean-Core-2f-System:
	-$(RM) ./Core/System/system.cyclo ./Core/System/system.d ./Core/System/system.o ./Core/System/system.su

.PHONY: clean-Core-2f-System

