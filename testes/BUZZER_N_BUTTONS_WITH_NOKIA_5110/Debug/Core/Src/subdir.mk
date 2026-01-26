################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/app.c \
../Core/Src/buttons.c \
../Core/Src/buzzer.c \
../Core/Src/display.c \
../Core/Src/lcd_pcd8544.c \
../Core/Src/lcd_pcd8544_ll.c \
../Core/Src/logo_bitmap.c \
../Core/Src/main.c \
../Core/Src/screen_logo.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/app.o \
./Core/Src/buttons.o \
./Core/Src/buzzer.o \
./Core/Src/display.o \
./Core/Src/lcd_pcd8544.o \
./Core/Src/lcd_pcd8544_ll.o \
./Core/Src/logo_bitmap.o \
./Core/Src/main.o \
./Core/Src/screen_logo.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/app.d \
./Core/Src/buttons.d \
./Core/Src/buzzer.d \
./Core/Src/display.d \
./Core/Src/lcd_pcd8544.d \
./Core/Src/lcd_pcd8544_ll.d \
./Core/Src/logo_bitmap.d \
./Core/Src/main.d \
./Core/Src/screen_logo.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/app.cyclo ./Core/Src/app.d ./Core/Src/app.o ./Core/Src/app.su ./Core/Src/buttons.cyclo ./Core/Src/buttons.d ./Core/Src/buttons.o ./Core/Src/buttons.su ./Core/Src/buzzer.cyclo ./Core/Src/buzzer.d ./Core/Src/buzzer.o ./Core/Src/buzzer.su ./Core/Src/display.cyclo ./Core/Src/display.d ./Core/Src/display.o ./Core/Src/display.su ./Core/Src/lcd_pcd8544.cyclo ./Core/Src/lcd_pcd8544.d ./Core/Src/lcd_pcd8544.o ./Core/Src/lcd_pcd8544.su ./Core/Src/lcd_pcd8544_ll.cyclo ./Core/Src/lcd_pcd8544_ll.d ./Core/Src/lcd_pcd8544_ll.o ./Core/Src/lcd_pcd8544_ll.su ./Core/Src/logo_bitmap.cyclo ./Core/Src/logo_bitmap.d ./Core/Src/logo_bitmap.o ./Core/Src/logo_bitmap.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/screen_logo.cyclo ./Core/Src/screen_logo.d ./Core/Src/screen_logo.o ./Core/Src/screen_logo.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su

.PHONY: clean-Core-2f-Src

