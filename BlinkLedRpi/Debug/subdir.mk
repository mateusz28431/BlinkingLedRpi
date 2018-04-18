################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BlinkingThread.cpp \
../CommonThread.cpp \
../RpiGPIO.cpp \
../ShellCommand.cpp \
../main.cpp 

OBJS += \
./BlinkingThread.o \
./CommonThread.o \
./RpiGPIO.o \
./ShellCommand.o \
./main.o 

CPP_DEPS += \
./BlinkingThread.d \
./CommonThread.d \
./RpiGPIO.d \
./ShellCommand.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


