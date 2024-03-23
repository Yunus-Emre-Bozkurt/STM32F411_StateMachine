################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/application.c \
../source/i2c_app.c \
../source/timer.c \
../source/uart_app.c 

OBJS += \
./source/application.o \
./source/i2c_app.o \
./source/timer.o \
./source/uart_app.o 

C_DEPS += \
./source/application.d \
./source/i2c_app.d \
./source/timer.d \
./source/uart_app.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o source/%.su source/%.cyclo: ../source/%.c source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../USB_HOST/App -I"C:/Users/Agrica/Desktop/DESKTOP/Projeler/StateMachine/work/STM32F411_StateMachine/DiscoF411_StateMachine/source" -I../USB_HOST/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-source

clean-source:
	-$(RM) ./source/application.cyclo ./source/application.d ./source/application.o ./source/application.su ./source/i2c_app.cyclo ./source/i2c_app.d ./source/i2c_app.o ./source/i2c_app.su ./source/timer.cyclo ./source/timer.d ./source/timer.o ./source/timer.su ./source/uart_app.cyclo ./source/uart_app.d ./source/uart_app.o ./source/uart_app.su

.PHONY: clean-source

