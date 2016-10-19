##################################################
# Makefile of pmtestx.asm (x=[1,2,3...])
##################################################

SRC:=boot.asm
BIN:=$(subst .asm,.bin,$(SRC))
IMG	= a.img

.PHONY : everything clean final all realclean

everything : $(BIN) $(IMG)
	dd if=$(BIN) of=$(IMG) bs=512 count=1 conv=notrunc

all: realclean everything 
	
	
realclean:
	rm -f $(BIN) $(IMG)

$(BIN) : $(SRC)
	nasm $< -o $@

clean:
	rm -f $(BIN)

$(IMG):
	qemu-img create -f raw $@ 1440K;
