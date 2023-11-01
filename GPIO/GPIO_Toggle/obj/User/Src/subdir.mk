################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Src/dshot.c \
../User/Src/functions.c \
../User/Src/main.c \
../User/Src/phaseouts.c \
../User/Src/signal.c \
../User/Src/sounds.c 

OBJS += \
./User/Src/dshot.o \
./User/Src/functions.o \
./User/Src/main.o \
./User/Src/phaseouts.o \
./User/Src/signal.o \
./User/Src/sounds.o 

C_DEPS += \
./User/Src/dshot.d \
./User/Src/functions.d \
./User/Src/main.d \
./User/Src/phaseouts.d \
./User/Src/signal.d \
./User/Src/sounds.d 


# Each subdirectory must supply rules for building sources it contributes
User/Src/%.o: ../User/Src/%.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

