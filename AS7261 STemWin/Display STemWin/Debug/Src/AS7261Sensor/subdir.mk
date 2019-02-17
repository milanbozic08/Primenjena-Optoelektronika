################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/AS7261Sensor/ASMaster.c \
../Src/AS7261Sensor/AS_ATCommands.c \
../Src/AS7261Sensor/StringFunction.c 

OBJS += \
./Src/AS7261Sensor/ASMaster.o \
./Src/AS7261Sensor/AS_ATCommands.o \
./Src/AS7261Sensor/StringFunction.o 

C_DEPS += \
./Src/AS7261Sensor/ASMaster.d \
./Src/AS7261Sensor/AS_ATCommands.d \
./Src/AS7261Sensor/StringFunction.d 


# Each subdirectory must supply rules for building sources it contributes
Src/AS7261Sensor/%.o: ../Src/AS7261Sensor/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Inc" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/CMSIS/Include" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/Hardware/Inc" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/STemWinLib/inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


