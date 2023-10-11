#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material.
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <this make file will support HOST and MSP432 targets>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM =HOST

# other compile switch variables
VER =
COUR =

# general flags for all
GENFLAGS = -Wall -Werror\
           -g -O0 -std=c99

TARGET = c1m2
 
# platform dependent variables
ifeq ($(PLATFORM),MSP432)

	CPU = cortex-m4
	ARCH = armv7e-m

	SOURCES+= ./src/startup_msp432p401r_gcc.c \
		  ./src/system_msp432p401r.c \
		  ./src/interrupts_msp432p401r_gcc.c

	INCLUDES+= -I ./include/CMSIS/ \
		   -I ./include/msp432/

	# Compiler
	CC = arm-none-eabi-gcc

	# Linker
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size

	# Linker Flags
	LINKER_FILE = ./msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)

	# Compiler Flags
	CFLAGS = 	$(GENFLAGS) \
				-mcpu=$(CPU) \
				-mthumb \
				-march=$(ARCH) \
				-mfloat-abi=hard \
				-mfpu=fpv4-sp-d16\
				--specs=nosys.specs
	CPPFLAGS = -DMSP432 $(INCLUDES)

else
	# @echo Host platform detected
	CC = gcc
	CFLAGS = $(GENFLAGS)
	CPPFLAGS = -DHOST $(INCLUDES)
	SIZE = size

endif

ifeq ($(VER), VERBOSE)
	CPPFLAGS += -DVERBOSE
endif

ifeq ($(COUR), COURSE1)
	CPPFLAGS += -DCOURSE1
endif

PREP = $(SOURCES:.c=.i)	# Preprocessor Files
DEPS = $(SOURCES:.c=.d)	# Dependancy Files
ASMS = $(SOURCES:.c=.asm) # Assembly Files
OBJS = $(SOURCES:.c=.o)	# Object files

.PHONY: compile-all build clean

# Compile all object files and link into a final executable.
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

# Generate Preprocesed output of all c-program implementation files (use the -E flag)
%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate assembly output of c-program implementation files and the final output executable (Use the -S flag and the objdump utility).
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile.
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate Dependancy files for each Source File
%.d: %.c
	$(CC) -E -M $<  $(CPPFLAGS) -o $@

# Compile all object files, but DO NOT link.
compile-all: $(OBJS)

clean:
	# This should remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
	@echo Removing all built files
	rm -f ./*.out ./*.map ./src/*.o ./src/*.asm ./src/*.i
