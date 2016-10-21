# Makefile for boot
include ../../../commk/Makefile

# Programs, flags, etc.
ASM_SEARCH_PATH		= -I include/

ASMFLAGS	= $(ASM_SEARCH_PATH)

# This Program
ASM_SRC		= boot.asm loader.asm
ASM_INCLUDE	= include/load.inc include/fat12hdr.inc include/pm.inc
TARGET		= boot.bin loader.bin

# All Phony Targets
.PHONY : everything clean all

# Default starting position
everything : $(TARGET)

clean :
	rm -f $(TARGET)

all : clean everything

%.bin: %.asm $(ASM_INCLUDE)
	$(ASM) $(ASMFLAGS) -o $@ $<
