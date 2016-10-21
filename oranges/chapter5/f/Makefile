#########################
# Makefile for Orange'S #
#########################
include ../../commk/Makefile

# Entry point of Orange'S
# It must have the same value with 'KernelEntryPointPhyAddr' in load.inc!
ENTRYPOINT	= 0x30400

# Programs, flags, etc.

LD_ENTRY_FLAGS		= -Ttext $(ENTRYPOINT)

# This Program
ORANGESBOOT			= boot.bin loader.bin 
ORANGESKERNEL		= kernel.bin 
OBJS				= kernel.o start.o string.o kliba.o
HEADS				= const.h protect.h type.h 
IMG 				= a.img 

LD_FLAGS 			+= $(ARC_I386) $(LD_ENTRY_FLAGS) $(STRIPALL)
GCC_FLAGS			+= $(GCC_ARC_I386) $(GCC_NO_BUILDIN) $(GCC_WARNING)
ASM_FLAGS			+= $(ELFFLAGS)
# All Phony Targets
.PHONY : everything final image clean realclean all buildimg

# Default starting position
everything : $(ORANGESBOOT) $(ORANGESKERNEL)

all : realclean everything

final : all clean

image : final buildimg

clean :
	rm -f $(OBJS) 

realclean :
	rm -f $(OBJS) $(ORANGESBOOT) $(ORANGESKERNEL) $(IMG)


# We assume that "a.img" exists in current folder
buildimg :$(IMG)
	dd if=boot.bin of=$(IMG) bs=512 count=1 conv=notrunc
	sudo mount -o loop $(IMG) /mnt/floppy/
	sudo cp -fv loader.bin /mnt/floppy/
	sudo cp -fv kernel.bin /mnt/floppy
	sudo umount /mnt/floppy

boot.bin : boot.asm load.inc fat12hdr.inc
	$(ASM) $(ASMBFLAGS) -o $@ $<

loader.bin : loader.asm load.inc fat12hdr.inc pm.inc
	$(ASM) $(ASMBFLAGS) -o $@ $<

$(ORANGESKERNEL) : $(OBJS)
	$(LD)  $(LD_FLAGS) -o $(ORANGESKERNEL) $(OBJS)

start.o : start.c type.h const.h protect.h
	$(CC) -c  $(GCC_FLAGS) -o $@ -I. $<

kernel.o : kernel.asm
	$(ASM) $(ASM_FLAGS) -o $@ $<

string.o : string.asm
	$(ASM) $(ASM_FLAGS) -o $@ $<

kliba.o : kliba.asm
	$(ASM) $(ASM_FLAGS) -o $@ $<

# generate a empty image file with size 1.44M as floppy.
$(IMG):
	qemu-img create -f raw $(IMG) 1440K;
