################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../HelloRPiWorld.cpp 

OBJS += \
./HelloRPiWorld.o 

CPP_DEPS += \
./HelloRPiWorld.d 


# Each subdirectory must supply rules for building sources it contributes
HelloRPiWorld.o: ../HelloRPiWorld.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -O2 -g3 -Wall -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7 -MMD -MP -MF"$(@:%.o=%.d)" -MT"HelloRPiWorld.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


