################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/MHC/Potentiometer.cpp 

OBJS += \
./Drivers/MHC/Potentiometer.o 

CPP_DEPS += \
./Drivers/MHC/Potentiometer.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MHC/%.o Drivers/MHC/%.su: ../Drivers/MHC/%.cpp Drivers/MHC/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -I../Drivers/MHC -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-MHC

clean-Drivers-2f-MHC:
	-$(RM) ./Drivers/MHC/Potentiometer.d ./Drivers/MHC/Potentiometer.o ./Drivers/MHC/Potentiometer.su

.PHONY: clean-Drivers-2f-MHC

