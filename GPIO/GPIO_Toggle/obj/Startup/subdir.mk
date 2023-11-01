################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Startup/startup_ch32v20x_D6.S 

OBJS += \
./Startup/startup_ch32v20x_D6.o 

S_UPPER_DEPS += \
./Startup/startup_ch32v20x_D6.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_ch32v20x_D6.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Startup/startup_ch32v20x_D6.S
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -x assembler-with-cpp -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Startup" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

