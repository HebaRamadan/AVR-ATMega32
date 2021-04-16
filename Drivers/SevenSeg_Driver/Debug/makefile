################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Prof_SevenSeg_Driver.lss \

FLASH_IMAGE += \
Prof_SevenSeg_Driver.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Prof_SevenSeg_Driver.elf secondary-outputs

# Tool invocations
Prof_SevenSeg_Driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Prof_SevenSeg_Driver.map -mmcu=atmega32 -o "Prof_SevenSeg_Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Prof_SevenSeg_Driver.lss: Prof_SevenSeg_Driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Prof_SevenSeg_Driver.elf  >"Prof_SevenSeg_Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

Prof_SevenSeg_Driver.hex: Prof_SevenSeg_Driver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Prof_SevenSeg_Driver.elf  "Prof_SevenSeg_Driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Prof_SevenSeg_Driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Prof_SevenSeg_Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Prof_SevenSeg_Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
