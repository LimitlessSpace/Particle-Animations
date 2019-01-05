################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Particle.cpp \
../src/Screen.cpp \
../src/Swarm.cpp \
../src/main.cpp 

OBJS += \
./src/Particle.o \
./src/Screen.o \
./src/Swarm.o \
./src/main.o 

CPP_DEPS += \
./src/Particle.d \
./src/Screen.d \
./src/Swarm.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/dennis/Documents/Programming/Libraries/SDL2 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


