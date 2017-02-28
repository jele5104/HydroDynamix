################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MAX11043.c \
../src/main.c \
../src/syscalls.c \
../src/system_stm32f4xx.c \
../src/tm_stm32f4_delay.c \
../src/tm_stm32f4_gpio.c \
../src/tm_stm32f4_mco_output.c \
../src/tm_stm32f4_spi.c \
../src/tm_stm32f4_timer_properties.c 

OBJS += \
./src/MAX11043.o \
./src/main.o \
./src/syscalls.o \
./src/system_stm32f4xx.o \
./src/tm_stm32f4_delay.o \
./src/tm_stm32f4_gpio.o \
./src/tm_stm32f4_mco_output.o \
./src/tm_stm32f4_spi.o \
./src/tm_stm32f4_timer_properties.o 

C_DEPS += \
./src/MAX11043.d \
./src/main.d \
./src/syscalls.d \
./src/system_stm32f4xx.d \
./src/tm_stm32f4_delay.d \
./src/tm_stm32f4_gpio.d \
./src/tm_stm32f4_mco_output.d \
./src/tm_stm32f4_spi.d \
./src/tm_stm32f4_timer_properties.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F411VETx -DSTM32F4 -DSTM32 -DSTM32F411E_DISCO -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F411xE -I"C:/Users/Matt/2017-Spring/capstone/SPI_basic_test/SPI_for_MAX/SPI_test/inc" -I"C:/Users/Matt/2017-Spring/capstone/SPI_basic_test/SPI_for_MAX/SPI_test/CMSIS/core" -I"C:/Users/Matt/2017-Spring/capstone/SPI_basic_test/SPI_for_MAX/SPI_test/CMSIS/device" -I"C:/Users/Matt/2017-Spring/capstone/SPI_basic_test/SPI_for_MAX/SPI_test/StdPeriph_Driver/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


