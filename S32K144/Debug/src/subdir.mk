################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/Appl.c" \
"../src/InterruptServices.c" \
"../src/TaskEntity.c" \

C_SRCS += \
../src/Appl.c \
../src/InterruptServices.c \
../src/TaskEntity.c \

OBJS_OS_FORMAT += \
./src/Appl.o \
./src/InterruptServices.o \
./src/TaskEntity.o \

C_DEPS_QUOTED += \
"./src/Appl.d" \
"./src/InterruptServices.d" \
"./src/TaskEntity.d" \

OBJS += \
./src/Appl.o \
./src/InterruptServices.o \
./src/TaskEntity.o \

OBJS_QUOTED += \
"./src/Appl.o" \
"./src/InterruptServices.o" \
"./src/TaskEntity.o" \

C_DEPS += \
./src/Appl.d \
./src/InterruptServices.d \
./src/TaskEntity.d \


# Each subdirectory must supply rules for building sources it contributes
src/Appl.o: ../src/Appl.c
	@echo 'Building file: $<'
	@echo 'Executing target #92 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/Appl.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/Appl.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/InterruptServices.o: ../src/InterruptServices.c
	@echo 'Building file: $<'
	@echo 'Executing target #93 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/InterruptServices.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/InterruptServices.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/TaskEntity.o: ../src/TaskEntity.c
	@echo 'Building file: $<'
	@echo 'Executing target #94 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/TaskEntity.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/TaskEntity.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


