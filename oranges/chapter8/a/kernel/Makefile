# Makefile for boot
include ../../../commk/Makefile

# Programs, flags, etc.
ASM_SEARCH_PATH		= -I./ -I ../include/ 
GCC_COMP_SEARCH_PATH= $(GCC_NO_STDINC) -I ../include/ 
ASMFLAGS	= $(ASM_SEARCH_PATH) $(ELFFLAGS)

# This Program
ASM_SRC		= kernel.asm syscall.asm
ASM_INCLUDE	= 
CFLAGS		= $(GCC_COMP_SEARCH_PATH) $(GCC_NO_BUILDIN) $(GCC_ARC_I386) $(GCC_WARNING) $(GCC_NO_STACK_PROTECT) $(GCC_COMPILE)
#GCC_INCLUDE	= ../include/type.h ../include/const.h ../include/protect.h ../include/global.h ../include/proto.h
TARGET		= clock.o global.o i8259.o kernel.o main.o proc.o protect.o start.o syscall.o keyboard.o tty.o console.o printf.o systask.o vsprintf.o

# All Phony Targets
.PHONY : everything clean all

# Default starting position
everything : $(TARGET)

clean :
	rm -f $(TARGET)

all : clean everything


%.o : %.c $(GCC_INCLUDE)
	$(CC) $(CFLAGS) -o $@ $<
	
%.o: %.asm $(ASM_INCLUDE)
	$(ASM) $(ASMFLAGS) -o $@ $<

