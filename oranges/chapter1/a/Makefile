#This is makefile for boot module
include ../../commk/Makefile

SIMULATOR=qemu-system-i386

TARGET	=	boot.bin
RAMIMG	=	boot.img

INCLUDE	=
#SRC_C=loader.c
SRC_S	=	boot.asm
IMG		=	boot.img

.PHONY: everything final clean realclean copyhing simulate all building

everything: $(TARGET)
	

all: realclean everything

clean:
	rm -f $(TARGET) *.txt;
	
realclean: clean 
	rm -f $(RAMIMG);

image:final building

building:$(IMG)
	dd if=$(TARGET) of=$(IMG) bs=512 count=1 conv=notrunc;
	
simulate:$(RAMIMG)
	$(SIMULATOR) -hda $(RAMIMG);

copyimg:
	cp ../tools/emptyFloppy.img ./a.img;

$(RAMIMG):
	qemu-img create -f raw $(IMG) 1440K;


$(TARGET):$(SRC_S)
	$(ASM)	$(SRC_S) -o $(TARGET);	


%.o:%.c $(INCLUDE)
	$(CC) -c %< -o %@
