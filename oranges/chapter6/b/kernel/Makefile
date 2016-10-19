# Makefile for boot
include ../../../commk/Makefile

# Programs, flags, etc.
ASM_SEARCH_PATH		= -I ../include/ 
GCC_COMP_SEARCH_PATH= $(GCC_NO_STDINC) -I ../include/ 
ASMFLAGS	= $(ASM_SEARCH_PATH) $(ELFFLAGS)

# This Program
ASM_SRC		= kernel.final.asm kernel1.asm kernel2.asm kernel3.asm kernel4.asm kernel5.asm
ASM_INCLUDE	= 
CFLAGS		= $(GCC_COMP_SEARCH_PATH) $(GCC_NO_BUILDIN) $(GCC_ARC_I386) $(GCC_WARNING) $(GCC_NO_STACK_PROTECT) $(GCC_COMPILE)
#GCC_INCLUDE	= ../include/type.h ../include/const.h ../include/protect.h ../include/global.h ../include/proto.h
TARGET		= kernel.o start.o global.o i8259.o protect.o main.o

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
