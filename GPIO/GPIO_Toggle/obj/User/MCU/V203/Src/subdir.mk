################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/MCU/V203/Src/ADC.c \
../User/MCU/V203/Src/IO.c \
../User/MCU/V203/Src/ch32v20x_it.c \
../User/MCU/V203/Src/comparator.c \
../User/MCU/V203/Src/eeprom.c \
../User/MCU/V203/Src/peripherals.c \
../User/MCU/V203/Src/serial_telemetry.c \
../User/MCU/V203/Src/system_ch32v20x.c 

OBJS += \
./User/MCU/V203/Src/ADC.o \
./User/MCU/V203/Src/IO.o \
./User/MCU/V203/Src/ch32v20x_it.o \
./User/MCU/V203/Src/comparator.o \
./User/MCU/V203/Src/eeprom.o \
./User/MCU/V203/Src/peripherals.o \
./User/MCU/V203/Src/serial_telemetry.o \
./User/MCU/V203/Src/system_ch32v20x.o 

C_DEPS += \
./User/MCU/V203/Src/ADC.d \
./User/MCU/V203/Src/IO.d \
./User/MCU/V203/Src/ch32v20x_it.d \
./User/MCU/V203/Src/comparator.d \
./User/MCU/V203/Src/eeprom.d \
./User/MCU/V203/Src/peripherals.d \
./User/MCU/V203/Src/serial_telemetry.d \
./User/MCU/V203/Src/system_ch32v20x.d 


# Each subdirectory must supply rules for building sources it contributes
User/MCU/V203/Src/%.o: ../User/MCU/V203/Src/%.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

