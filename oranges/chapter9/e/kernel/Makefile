# Makefile for boot
include ../../../commk/Makefile

# Programs, flags, etc.
ASM_SEARCH_PATH		= -I./ -I ../include/ -I ../include/sys/
GCC_COMP_SEARCH_PATH= $(GCC_NO_STDINC) -I ../include/ -I ../include/sys/
ASMFLAGS	= $(ASM_SEARCH_PATH) $(ELFFLAGS)

# This Program
ASM_SRC		= kernel.asm
ASM_INCLUDE	= 
CFLAGS		= $(GCC_COMP_SEARCH_PATH) $(GCC_NO_BUILDIN) $(GCC_ARC_I386) $(GCC_WARNING) $(GCC_NO_STACK_PROTECT) $(GCC_COMPILE)
#GCC_INCLUDE	= ../include/type.h ../include/const.h ../include/protect.h ../include/global.h ../include/proto.h
TARGET		= clock.o console.o global.o hd.o i8259.o keyboard.o main.o proc.o protect.o start.o systask.o tty.o kernel.o

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

