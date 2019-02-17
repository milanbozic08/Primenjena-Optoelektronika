################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/AS7261Sensor/AS_Windows/WindowCalibratedDataNewDLG.c \
../Src/AS7261Sensor/AS_Windows/WindowConfigDLG.c \
../Src/AS7261Sensor/AS_Windows/WindowConnectDLG.c \
../Src/AS7261Sensor/AS_Windows/WindowGainDLG.c \
../Src/AS7261Sensor/AS_Windows/WindowIntTimeDLG.c \
../Src/AS7261Sensor/AS_Windows/WindowLEDDLG.c \
../Src/AS7261Sensor/AS_Windows/WindowMenuDLG.c \
../Src/AS7261Sensor/AS_Windows/WindowModeDLG.c \
../Src/AS7261Sensor/AS_Windows/WindowRAWDLG.c \
../Src/AS7261Sensor/AS_Windows/WindowSmpIntervalDLG.c 

OBJS += \
./Src/AS7261Sensor/AS_Windows/WindowCalibratedDataNewDLG.o \
./Src/AS7261Sensor/AS_Windows/WindowConfigDLG.o \
./Src/AS7261Sensor/AS_Windows/WindowConnectDLG.o \
./Src/AS7261Sensor/AS_Windows/WindowGainDLG.o \
./Src/AS7261Sensor/AS_Windows/WindowIntTimeDLG.o \
./Src/AS7261Sensor/AS_Windows/WindowLEDDLG.o \
./Src/AS7261Sensor/AS_Windows/WindowMenuDLG.o \
./Src/AS7261Sensor/AS_Windows/WindowModeDLG.o \
./Src/AS7261Sensor/AS_Windows/WindowRAWDLG.o \
./Src/AS7261Sensor/AS_Windows/WindowSmpIntervalDLG.o 

C_DEPS += \
./Src/AS7261Sensor/AS_Windows/WindowCalibratedDataNewDLG.d \
./Src/AS7261Sensor/AS_Windows/WindowConfigDLG.d \
./Src/AS7261Sensor/AS_Windows/WindowConnectDLG.d \
./Src/AS7261Sensor/AS_Windows/WindowGainDLG.d \
./Src/AS7261Sensor/AS_Windows/WindowIntTimeDLG.d \
./Src/AS7261Sensor/AS_Windows/WindowLEDDLG.d \
./Src/AS7261Sensor/AS_Windows/WindowMenuDLG.d \
./Src/AS7261Sensor/AS_Windows/WindowModeDLG.d \
./Src/AS7261Sensor/AS_Windows/WindowRAWDLG.d \
./Src/AS7261Sensor/AS_Windows/WindowSmpIntervalDLG.d 


# Each subdirectory must supply rules for building sources it contributes
Src/AS7261Sensor/AS_Windows/%.o: ../Src/AS7261Sensor/AS_Windows/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Inc" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/CMSIS/Include" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/Drivers/Hardware/Inc" -I"C:/Users/milan/OneDrive/Desktop/Project XYZSensor/AS7261 STemWin/Display STemWin/STemWinLib/inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


