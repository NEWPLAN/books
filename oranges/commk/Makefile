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
#	GCC_NO_STDINC is parameter to switch off search from stdinclude lib,just search from the -I path

ELFFLAGS		=	-f elf 
STRIPALL		=	-s 
ARC_I386		=	-m elf_i386 
#	ASM_ELFFLAGS is parameters of NASM to generate 32bit ELF file
#	ASM_ARC_I386 is parameters of LD to link a x86-32bit code
#	ASM_STRIPALL is parameter of LD to erase all symbols, make execode thinner.
ASM_ELFFLAGS	=	-f elf 
ASM_ARC_I386	=	-m elf_i386 
ASM_STRIPALL	=	-s 
#	GCC_NO_BUILDIN is parameter to point our local lib without global libs.
#	GCC_NO_STDINC is parameter to switch off search from stdinclude lib,just search from the -I path
#	GCC_WARNING is a parameter for end up compiling while get some warnings, just to make the code more leagal 
#	GCC_NO_STACK_PROTECT is a parameter to disable the switch of stack protect.
GCC_NO_BUILDIN			=	-fno-builtin 
GCC_NO_STDINC			=	-nostdinc
GCC_WARNING				=	-Wall -Wextra
GCC_ARC_I386			=	-m32
GCC_COMPILE				=	-c
GCC_NO_STACK_PROTECT	=	-fno-stack-protector

