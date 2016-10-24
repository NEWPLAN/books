#########################
# Makefile for Orange'S #
#########################

# Entry point of Orange'S
# It must have the same value with 'KernelEntryPointPhyAddr' in load.inc!
ENTRYPOINT	= 0x30400
include ../../commk/Makefile
# Offset of entry point in kernel file
# It depends on ENTRYPOINT
ENTRYOFFSET	= 0x400

DASM		:= objdump

# Programs, flags, etc.
ASM_BOOT_SEARCH_PATH 	= -I boot/include/
ASM_KERNEL_SEARCH_PATH	= -I include/
GCC_COMP_SEARCH_PATH	= -I include/ $(GCC_NO_STDINC) 

LD_MAP					= #-Map krnl.map
# compile parameters
ASMBFLAGS	= $(ASM_BOOT_SEARCH_PATH)
ASMKFLAGS	= $(ASM_KERNEL_SEARCH_PATH) $(ELFFLAGS)
CFLAGS		= $(GCC_COMP_SEARCH_PATH) $(GCC_COMPILE) $(GCC_NO_BUILDIN) $(GCC_ARC_I386) $(GCC_NO_STACK_PROTECT) 
LDFLAGS		= $(STRIPALL) -Ttext $(ENTRYPOINT) $(ARC_I386) $(LD_MAP)
DASMFLAGS	= -D

# different objs from different folders
OBJ_KERNEL	= kernel/kernel.o kernel/syscall.o kernel/start.o kernel/main.o kernel/clock.o kernel/keyboard.o kernel/i8259.o kernel/tty.o kernel/global.o kernel/protect.o kernel/proc.o kernel/console.o kernel/printf.o kernel/vsprintf.o kernel/systask.o kernel/hd.o

OBJ_LIB		= lib/kliba.o lib/klib.o lib/string.o lib/misc.o

OBJ_FS		= fs/main.o

# This Program
ORANGESBOOT	= boot/boot.bin boot/loader.bin
ORANGESKERNEL	= kernel.bin
OBJS		= $(OBJ_KERNEL) $(OBJ_LIB) $(OBJ_FS)
DASMOUTPUT	= kernel.bin.asm
IMG			= a.img

# All Phony Targets
.PHONY : everything final image clean realclean disasm all buildimg

# Default starting position
nop :
	@echo "why not \`make image' huh? :)"


everything : $(ORANGESBOOT) $(ORANGESKERNEL)

all : realclean everything

final : all clean

image : final buildimg

clean :
	make clean -C kernel;
	make clean -C lib;
	make clean -C boot;
	make clean -C fs;

realclean : clean	
	rm -f $(IMG) $(ORANGESKERNEL);

disasm :
	$(DASM) $(DASMFLAGS) $(ORANGESKERNEL) > $(DASMOUTPUT)

# We assume that "a.img" exists in current folder
buildimg : $(IMG)
	dd if=boot/boot.bin of=$(IMG) bs=512 count=1 conv=notrunc
	sudo mount -o loop $(IMG) /mnt/floppy/
	sudo cp -fv boot/loader.bin /mnt/floppy/
	sudo cp -fv $(ORANGESKERNEL) /mnt/floppy
	sudo umount /mnt/floppy

boot/boot.bin : 
	make boot.bin -C boot;

boot/loader.bin :
	make loader.bin -C boot;

$(ORANGESKERNEL) : $(OBJS)
	$(LD) $(LDFLAGS) -o $(ORANGESKERNEL) $(OBJS)

$(OBJ_KERNEL):
	make -C kernel;
	
$(OBJ_LIB):
	make -C lib;

$(OBJ_FS):
	make -C fs;
	
$(IMG):
	qemu-img create -f raw $(IMG) 1440K;

