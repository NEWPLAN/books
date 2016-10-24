# Makefile for boot
include ../../../commk/Makefile

# Programs, flags, etc.
ASM_SEARCH_PATH		= -I ./ -I ../include/ -I ../include/sys/
GCC_COMP_SEARCH_PATH= -I ../include/ -I ../include/sys/ $(GCC_NO_STDINC) 
ASMFLAGS	= $(ASM_SEARCH_PATH) $(ELFFLAGS)

# This Program
ASM_SRC		= kliba.asm string.asm syscall.asm
ASM_INCLUDE	= 

C_SRC		= close.c klib.c misc.c open.c printf.c vsprintf.c

CFLAGS		= $(GCC_COMP_SEARCH_PATH) $(GCC_COMPILE) $(GCC_NO_BUILDIN) $(GCC_ARC_I386) $(GCC_WARNING) $(GCC_NO_STACK_PROTECT) 
GCC_INCLUDE	= #../include/type.h ../include/const.h ../include/protect.h ../include/string.h ../include/global.h 

TARGET		= close.o kliba.o klib.o misc.o open.o printf.o string.o syscall.o vsprintf.o

# All Phony Targets
.PHONY : everything clean all

# Default starting position
everything : $(TARGET)

clean :
	rm -f $(TARGET)

all : clean everything

# C files
%.o:%.c $(GCC_INCLUDE)
	$(CC) $(CFLAGS) -o $@ $<

# ASM file
%.o: %.asm $(ASM_INCLUDE)
	$(ASM) $(ASMFLAGS) -o $@ $<

