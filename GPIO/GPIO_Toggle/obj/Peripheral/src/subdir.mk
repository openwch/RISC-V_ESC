################################################################################
# MRS Version: 1.9.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_adc.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_bkp.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_can.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_crc.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_dbgmcu.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_dma.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_exti.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_flash.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_gpio.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_i2c.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_iwdg.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_misc.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_opa.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_pwr.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_rcc.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_rtc.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_spi.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_tim.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_usart.c \
G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_wwdg.c 

OBJS += \
./Peripheral/src/ch32v20x_adc.o \
./Peripheral/src/ch32v20x_bkp.o \
./Peripheral/src/ch32v20x_can.o \
./Peripheral/src/ch32v20x_crc.o \
./Peripheral/src/ch32v20x_dbgmcu.o \
./Peripheral/src/ch32v20x_dma.o \
./Peripheral/src/ch32v20x_exti.o \
./Peripheral/src/ch32v20x_flash.o \
./Peripheral/src/ch32v20x_gpio.o \
./Peripheral/src/ch32v20x_i2c.o \
./Peripheral/src/ch32v20x_iwdg.o \
./Peripheral/src/ch32v20x_misc.o \
./Peripheral/src/ch32v20x_opa.o \
./Peripheral/src/ch32v20x_pwr.o \
./Peripheral/src/ch32v20x_rcc.o \
./Peripheral/src/ch32v20x_rtc.o \
./Peripheral/src/ch32v20x_spi.o \
./Peripheral/src/ch32v20x_tim.o \
./Peripheral/src/ch32v20x_usart.o \
./Peripheral/src/ch32v20x_wwdg.o 

C_DEPS += \
./Peripheral/src/ch32v20x_adc.d \
./Peripheral/src/ch32v20x_bkp.d \
./Peripheral/src/ch32v20x_can.d \
./Peripheral/src/ch32v20x_crc.d \
./Peripheral/src/ch32v20x_dbgmcu.d \
./Peripheral/src/ch32v20x_dma.d \
./Peripheral/src/ch32v20x_exti.d \
./Peripheral/src/ch32v20x_flash.d \
./Peripheral/src/ch32v20x_gpio.d \
./Peripheral/src/ch32v20x_i2c.d \
./Peripheral/src/ch32v20x_iwdg.d \
./Peripheral/src/ch32v20x_misc.d \
./Peripheral/src/ch32v20x_opa.d \
./Peripheral/src/ch32v20x_pwr.d \
./Peripheral/src/ch32v20x_rcc.d \
./Peripheral/src/ch32v20x_rtc.d \
./Peripheral/src/ch32v20x_spi.d \
./Peripheral/src/ch32v20x_tim.d \
./Peripheral/src/ch32v20x_usart.d \
./Peripheral/src/ch32v20x_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/src/ch32v20x_adc.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_adc.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_bkp.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_bkp.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_can.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_can.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_crc.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_crc.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_dbgmcu.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_dbgmcu.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_dma.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_dma.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_exti.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_exti.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_flash.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_flash.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_gpio.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_gpio.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_i2c.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_i2c.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_iwdg.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_iwdg.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_misc.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_misc.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_opa.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_opa.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_pwr.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_pwr.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_rcc.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_rcc.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_rtc.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_rtc.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_spi.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_spi.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_tim.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_tim.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_usart.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_usart.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32v20x_wwdg.o: G:/ESC_V203/CH32V203_ESC/V203_AM32_PA0/SRC/Peripheral/src/ch32v20x_wwdg.c
	@	@	riscv-none-elf-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Inc" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User\MCU\V203\Src" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Debug" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Core" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\GPIO\GPIO_Toggle\User" -I"G:\ESC_V203\CH32V203_ESC\V203_AM32_PA0\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

