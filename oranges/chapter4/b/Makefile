##################################################
# Makefile
##################################################

BOOT:=boot.asm
LDR:=loader.asm
BOOT_BIN:=$(subst .asm,.bin,$(BOOT))
LDR_BIN:=$(subst .asm,.bin,$(LDR))
IMG	= a.img

.PHONY : everything clean 

everything : $(BOOT_BIN) $(LDR_BIN) $(IMG)
	dd if=$(BOOT_BIN) of=$(IMG) bs=512 count=1 conv=notrunc
	sudo mount -o loop $(IMG) /mnt/floppy/
	sudo cp $(LDR_BIN) /mnt/floppy/ -v
	sudo umount /mnt/floppy/

clean : 
	rm -f $(BOOT_BIN) $(LDR_BIN)

realclean : clean
	rm -f $(IMG)

$(BOOT_BIN) : $(BOOT)
	nasm $< -o $@

$(LDR_BIN) : $(LDR)
	nasm $< -o $@
	
$(IMG):
	qemu-img create -f raw $(IMG) 1440K;

