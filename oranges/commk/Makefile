# this is the common makefile , you should include it before using it.
# the follw is tools
#	CC is the gcc compiler;
#	CPP is g++ complier;
#	LD is the ld linker;
#	ASM is nasm the assembler;
#	DASM is anti-assembler.
CC		=	gcc 
CPP		=	g++
LD		=	ld
ASM		=	nasm
DASM	=	ndisasm

#	ELFFLAS is parameters of NASM to generate 32bit ELF file
#	ARC_I386 is parameters of LD to link a x86-32bit code
#	STRIPALL is parameter of LD to erase all symbols, make execode thinner.
#	GCC_NO_BUILDIN is parameter to point our local lib without global libs.
ELFFLAGS		=	-f elf 
ARC_I386		=	-m elf_i386 
STRIPALL		=	-s 
GCC_NO_BUILDIN	=	-fno-builtin 
GCC_ARC_I386	=	-m32