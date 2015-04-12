################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GPIOAccess.cpp \
../Sender.cpp \
../TCPSender.cpp \
../test.cpp 

OBJS += \
./GPIOAccess.o \
./Sender.o \
./TCPSender.o \
./test.o 

CPP_DEPS += \
./GPIOAccess.d \
./Sender.d \
./TCPSender.d \
./test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I/usr/local/wiringPi/wiringPi -I../Communication -O2 -g3 -Wall -c -lwiringPi -fmessage-length=0 -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


