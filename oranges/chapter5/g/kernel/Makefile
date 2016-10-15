# Makefile for boot
include ../../../commk/Makefile

# Programs, flags, etc.
ASM_SEARCH_PATH		= -I ./
GCC_COMP_SEARCH_PATH= -I ../include/
ASMFLAGS	= $(ASM_SEARCH_PATH) $(ELFFLAGS)

# This Program
ASM_SRC		= kernel.asm
ASM_INCLUDE	= 
CFLAGS		= $(GCC_COMP_SEARCH_PATH) $(GCC_COMPILE) $(GCC_NO_BUILDIN) $(GCC_ARC_I386) 
GCC_INCLUDE	= ../include/type.h ../include/const.h ../include/protect.h
TARGET		= kernel.o start.o

# All Phony Targets
.PHONY : everything clean all

# Default starting position
everything : $(TARGET)

clean :
	rm -f $(TARGET)

all : clean everything

kernel.o: kernel.asm $(ASM_INCLUDE)
	$(ASM) $(ASMFLAGS) -o $@ $<

start.o:start.c $(GCC_INCLUDE)
	$(CC) $(CFLAGS) -o $@ $<