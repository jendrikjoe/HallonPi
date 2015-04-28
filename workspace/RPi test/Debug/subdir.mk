################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ADCCommunicationPackage.cpp \
../ADCRead.cpp \
../CommandCommunicationPackage.cpp \
../CommandExecuter.cpp \
../CommunicationPackage.cpp \
../GPIOAccess.cpp \
../HallonThread.cpp \
../HousekeepingCollector.cpp \
../HousekeepingCommunicationPackage.cpp \
../Sender.cpp \
../TCPReceiver.cpp \
../TCPSender.cpp \
../TCPServer.cpp \
../test.cpp 

OBJS += \
./ADCCommunicationPackage.o \
./ADCRead.o \
./CommandCommunicationPackage.o \
./CommandExecuter.o \
./CommunicationPackage.o \
./GPIOAccess.o \
./HallonThread.o \
./HousekeepingCollector.o \
./HousekeepingCommunicationPackage.o \
./Sender.o \
./TCPReceiver.o \
./TCPSender.o \
./TCPServer.o \
./test.o 

CPP_DEPS += \
./ADCCommunicationPackage.d \
./ADCRead.d \
./CommandCommunicationPackage.d \
./CommandExecuter.d \
./CommunicationPackage.d \
./GPIOAccess.d \
./HallonThread.d \
./HousekeepingCollector.d \
./HousekeepingCommunicationPackage.d \
./Sender.d \
./TCPReceiver.d \
./TCPSender.d \
./TCPServer.d \
./test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I/usr/local/wiringPi/wiringPi -O2 -g3 -Wall -c -lwiringPi -fmessage-length=0 -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


