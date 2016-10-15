#This is makefile for boot module
include ../../commk/Makefile

SIMULATOR=qemu-system-i386

TARGET	=	boot.bin

INCLUDE	=
#SRC_C=loader.c
SRC_S	=	boot.asm
IMG		=	a.img

.PHONY: everything final clean realclean copyhing simulate all building

everything: $(TARGET)
	

all: realclean everything

clean:
	rm -f *.txt;
	
realclean: clean 
	rm -f $(TARGET) $(IMG);

final:all clean

image:final building

building:$(IMG)
	dd if=$(TARGET) of=$(IMG) bs=512 count=1 conv=notrunc;
	
simulate:$(RAMIMG)
	$(SIMULATOR) -hda $(RAMIMG);

copyimg:
	cp ../tools/emptyFloppy.img ./a.img;

$(IMG):
	qemu-img create -f raw $(IMG) 1440K;


$(TARGET):$(SRC_S)
	$(ASM)	$(SRC_S) -o $(TARGET);	


%.o:%.c $(INCLUDE)
	$(CC) -c %< -o %@
