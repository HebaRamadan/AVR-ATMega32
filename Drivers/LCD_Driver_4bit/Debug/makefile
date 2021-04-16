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
__LCD_Driver_4bit.lss \

FLASH_IMAGE += \
__LCD_Driver_4bit.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: __LCD_Driver_4bit.elf secondary-outputs

# Tool invocations
__LCD_Driver_4bit.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,__LCD_Driver_4bit.map -mmcu=atmega32 -o "__LCD_Driver_4bit.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

__LCD_Driver_4bit.lss: __LCD_Driver_4bit.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S __LCD_Driver_4bit.elf  >"__LCD_Driver_4bit.lss"
	@echo 'Finished building: $@'
	@echo ' '

__LCD_Driver_4bit.hex: __LCD_Driver_4bit.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex __LCD_Driver_4bit.elf  "__LCD_Driver_4bit.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: __LCD_Driver_4bit.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 __LCD_Driver_4bit.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) __LCD_Driver_4bit.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
