################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Hardware/Src/SSD1963.c \
../Drivers/Hardware/Src/STMPE610.c 

OBJS += \
./Drivers/Hardware/Src/SSD1963.o \
./Drivers/Hardware/Src/STMPE610.o 

C_DEPS += \
./Drivers/Hardware/Src/SSD1963.d \
./Drivers/Hardware/Src/STMPE610.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Hardware/Src/%.o: ../Drivers/Hardware/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Inc" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/CMSIS/Include" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/Hardware/Inc" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/STemWinLib/inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


