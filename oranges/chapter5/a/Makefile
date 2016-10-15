#this is the makefile for compile .asm file in linux plantform using gcc and nasm

include ../../commk/Makefile


SRC=hello.asm

OBJ=$(subst .asm,.o,$(SRC)) 

EXE=$(subst .asm,.exe,$(SRC)) 



all : $(EXE)
	@echo "make done";

%.o : %.asm
	$(ASM) $(ELFFLAGS) $< -o $@
	
$(EXE) : $(OBJ)
	
	$(LD) $(ARC_I386) -s $< -o $@

.PHONY :c lean

clean:
	-rm -rf $(OBJ) $(EXE);
	@echo "clean done";
	
