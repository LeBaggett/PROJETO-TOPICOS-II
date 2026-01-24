################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Drivers/buttons.c \
../Core/Drivers/lcd.c \
../Core/Drivers/sd.c 

OBJS += \
./Core/Drivers/buttons.o \
./Core/Drivers/lcd.o \
./Core/Drivers/sd.o 

C_DEPS += \
./Core/Drivers/buttons.d \
./Core/Drivers/lcd.d \
./Core/Drivers/sd.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Drivers/%.o Core/Drivers/%.su Core/Drivers/%.cyclo: ../Core/Drivers/%.c Core/Drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/Menu" -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/Drivers" -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/Drivers" -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/Games" -I"D:/Program Files/STM IDE/Topicos II/Topicos II/Core/System" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Drivers

clean-Core-2f-Drivers:
	-$(RM) ./Core/Drivers/buttons.cyclo ./Core/Drivers/buttons.d ./Core/Drivers/buttons.o ./Core/Drivers/buttons.su ./Core/Drivers/lcd.cyclo ./Core/Drivers/lcd.d ./Core/Drivers/lcd.o ./Core/Drivers/lcd.su ./Core/Drivers/sd.cyclo ./Core/Drivers/sd.d ./Core/Drivers/sd.o ./Core/Drivers/sd.su

.PHONY: clean-Core-2f-Drivers

