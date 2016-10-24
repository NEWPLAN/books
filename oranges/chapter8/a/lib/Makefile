# Makefile for boot
include ../../../commk/Makefile

# Programs, flags, etc.
ASM_SEARCH_PATH		= -I ./ -I ../include/
GCC_COMP_SEARCH_PATH= -I ../include/ $(GCC_NO_STDINC) 
ASMFLAGS	= $(ASM_SEARCH_PATH) $(ELFFLAGS)

# This Program
ASM_SRC		= string.asm kliba.asm
ASM_INCLUDE	= 

C_SRC		= klib.c misc.c

CFLAGS		= $(GCC_COMP_SEARCH_PATH) $(GCC_COMPILE) $(GCC_NO_BUILDIN) $(GCC_ARC_I386) $(GCC_WARNING) $(GCC_NO_STACK_PROTECT) 
GCC_INCLUDE	= ../include/type.h ../include/const.h ../include/protect.h ../include/string.h ../include/global.h 

TARGET		= klib.o string.o kliba.o misc.o

# All Phony Targets
.PHONY : everything clean all

# Default starting position
everything : $(TARGET)

clean :
	rm -f $(TARGET)

all : clean everything

# C files
klib.o:klib.c $(GCC_INCLUDE)
	$(CC) $(CFLAGS) -o $@ $<

# ASM file
kliba.o: kliba.asm $(ASM_INCLUDE)
	$(ASM) $(ASMFLAGS) -o $@ $<

string.o: string.asm $(ASM_INCLUDE)
	$(ASM) $(ASMFLAGS) -o $@ $<

