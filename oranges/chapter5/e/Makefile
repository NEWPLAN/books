##################################################
# Makefile
##################################################
include ../../commk/Makefile
BOOT:=boot.asm
LDR:=loader.asm
KERNEL:=kernel.asm
BOOT_BIN:=$(subst .asm,.bin,$(BOOT))
LDR_BIN:=$(subst .asm,.bin,$(LDR))
KERNEL_BIN:=$(subst .asm,.bin,$(KERNEL))

IMG:=a.img
FLOPPY:=/mnt/floppy/

.PHONY : everything

everything : $(BOOT_BIN) $(LDR_BIN) $(KERNEL_BIN) $(IMG)
	dd if=$(BOOT_BIN) of=$(IMG) bs=512 count=1 conv=notrunc
	sudo mount -o loop $(IMG) $(FLOPPY)
	sudo cp $(LDR_BIN) $(FLOPPY) -v
	sudo cp $(KERNEL_BIN) $(FLOPPY) -v
	sudo umount $(FLOPPY)

clean :
	rm -f $(BOOT_BIN) $(LDR_BIN) $(KERNEL_BIN) *.o $(IMG)

$(BOOT_BIN) : $(BOOT)
	$(ASM) $< -o $@

$(LDR_BIN) : $(LDR)
	$(ASM) $< -o $@

$(KERNEL_BIN) : $(KERNEL)
	$(ASM) $(ELFFLAGS) -o $(subst .asm,.o,$(KERNEL)) $<
	$(LD) $(ARC_I386) $(STRIPALL) -Ttext 0x30400 -o $@ $(subst .asm,.o,$(KERNEL))
$(IMG):
	qemu-img create -f raw $(IMG) 1440K;
