################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

OBJS += \
./startup/startup_stm32.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo %cd%
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"C:/Users/Matt/2017-Spring/capstone/SPI_basic_test/SPI_for_MAX/SPI_test/inc" -I"C:/Users/Matt/2017-Spring/capstone/SPI_basic_test/SPI_for_MAX/SPI_test/CMSIS/core" -I"C:/Users/Matt/2017-Spring/capstone/SPI_basic_test/SPI_for_MAX/SPI_test/CMSIS/device" -I"C:/Users/Matt/2017-Spring/capstone/SPI_basic_test/SPI_for_MAX/SPI_test/StdPeriph_Driver/inc" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


