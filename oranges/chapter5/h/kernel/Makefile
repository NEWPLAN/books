# Makefile for boot
include ../../../commk/Makefile

# Programs, flags, etc.
ASM_SEARCH_PATH		= -I ./
GCC_COMP_SEARCH_PATH= -I ../include/ $(GCC_NO_STDINC) 
ASMFLAGS	= $(ASM_SEARCH_PATH) $(ELFFLAGS)

# This Program
ASM_SRC		= kernel.asm
ASM_INCLUDE	= 
CFLAGS		= $(GCC_COMP_SEARCH_PATH) $(GCC_COMPILE) $(GCC_NO_BUILDIN) $(GCC_ARC_I386) $(GCC_WARNING)
GCC_INCLUDE	= ../include/type.h ../include/const.h ../include/protect.h ../include/global.h ../include/proto.h
TARGET		= kernel.o start.o global.o i8259.o protect.o

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
	
global.o: global.c $(GCC_INCLUDE)
	$(CC) $(CFLAGS) -o $@ $<

i8259.o: i8259.c $(GCC_INCLUDE)
	$(CC) $(CFLAGS) -o $@ $<

protect.o: protect.c $(GCC_INCLUDE)
	$(CC) $(CFLAGS) -o $@ $<

