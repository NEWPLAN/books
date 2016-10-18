# Makefile for boot
include ../../../commk/Makefile

# Programs, flags, etc.
ASM_SEARCH_PATH		= -I ./

ASMFLAGS	= $(ASM_SEARCH_PATH) $(ELFFLAGS)

# This Program
ASM_SRC		= string.asm kliba.asm
ASM_INCLUDE	= 
TARGET		= string.o kliba.o

# All Phony Targets
.PHONY : everything clean all

# Default starting position
everything : $(TARGET)

clean :
	rm -f $(TARGET)

all : clean everything

%.o: %.asm $(ASM_INCLUDE)
	$(ASM) $(ASMFLAGS) -o $@ $<
