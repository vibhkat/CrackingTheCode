################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Chapter1.cpp \
../Chapter2.cpp \
../Chapter5.cpp \
../Chapter8.cpp \
../main.cpp 

OBJS += \
./Chapter1.o \
./Chapter2.o \
./Chapter5.o \
./Chapter8.o \
./main.o 

CPP_DEPS += \
./Chapter1.d \
./Chapter2.d \
./Chapter5.d \
./Chapter8.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/vibhanshu/Desktop/EclipseAlgorithmPractice/CrackingThecode" -I"/home/vibhanshu/Desktop/EclipseAlgorithmPractice/DoubleList/Header" -I"/home/vibhanshu/Desktop/EclipseAlgorithmPractice/ForwardLinkedList/header" -I"/home/vibhanshu/Desktop/EclipseAlgorithmPractice/StackDynamicArray/Header" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


