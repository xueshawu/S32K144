################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/Appl.c" \

C_SRCS += \
../src/Appl.c \

OBJS_OS_FORMAT += \
./src/Appl.o \

C_DEPS_QUOTED += \
"./src/Appl.d" \

OBJS += \
./src/Appl.o \

OBJS_QUOTED += \
"./src/Appl.o" \

C_DEPS += \
./src/Appl.d \


# Each subdirectory must supply rules for building sources it contributes
src/Appl.o: ../src/Appl.c
	@echo 'Building file: $<'
	@echo 'Executing target #75 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/Appl.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/Appl.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


