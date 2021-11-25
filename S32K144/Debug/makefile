################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 192
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Bsw/CanIf/subdir.mk
-include Bsw/CanIf/Integration/subdir.mk
-include Bsw/CanIf/src/subdir.mk
-include Bsw/CanTp/src/subdir.mk
-include Bsw/Crc/subdir.mk
-include Bsw/Dcm/subdir.mk
-include Bsw/Dcm/src/subdir.mk
-include Bsw/Dem/subdir.mk
-include Bsw/Dem/src/subdir.mk
-include Bsw/IoHwAb/src/subdir.mk
-include Bsw/NVM/subdir.mk
-include Bsw/NVM/src/subdir.mk
-include Bsw/PduR/src/subdir.mk
-include Bsw/SchM/src/subdir.mk
-include EBCfg/WorkspaceS32K144_19_06_2019/output/generated/src/subdir.mk
-include Mcal/Adc_TS_T40D2M10I1R0/src/subdir.mk
-include Mcal/Can_TS_T40D2M10I1R0/src/subdir.mk
-include Mcal/Det_TS_T40D2M10I1R0/src/subdir.mk
-include Mcal/Dio_TS_T40D2M10I1R0/src/subdir.mk
-include Mcal/EcuM_TS_T40D2M10I1R0/src/subdir.mk
-include Mcal/Fee_TS_T40D2M10I1R0/src/subdir.mk
-include Mcal/Fls_TS_T40D2M10I1R0/src/subdir.mk
-include Mcal/Gpt_TS_T40D2M10I1R0/src/subdir.mk
-include Mcal/Mcl_TS_T40D2M10I1R0/src/subdir.mk
-include Mcal/Mcu_TS_T40D2M10I1R0/src/subdir.mk
-include Mcal/Port_TS_T40D2M10I1R0/src/subdir.mk
-include Mcal/Pwm_TS_T40D2M10I1R0/src/subdir.mk
-include Mcal/Rte_TS_T40D2M10I1R0/src/subdir.mk
-include Os/cfg/subdir.mk
-include Os/src/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
S32K144.elf \

EXECUTABLES_QUOTED += \
"S32K144.elf" \

EXECUTABLES_OS_FORMAT += \
S32K144.elf \

SECONDARY_SIZE += \
S32K144.siz \

SECONDARY_SIZE_QUOTED += \
"S32K144.siz" \

SECONDARY_SIZE_OS_FORMAT += \
S32K144.siz \


# All Target
all: warning-messages explicit-dependencies S32K144.elf secondary-outputs

# Tool invocations
S32K144.elf: $(OBJS) E:/mywork/myproject/My_Github/S32K144/S32K144/Project_Settings/Linker_Files/S32K1xx_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #193 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "S32K144.elf" "@S32K144.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

S32K144.siz: $(EXECUTABLES)
	@echo 'Executing target #194 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*/*.d ./*/*/*.d ./*/*/*/*.d ./*/*/*/*/*/*.d  ./*/*.o ./*/*/*.o ./*/*/*/*.o ./*/*/*/*/*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

