all:
	gcc -m32 -fPIC  -c *.c -o pic.o
	ld -m elf_i386 -shared -fPIC pic.o -o pic.so

clean:
	rm -f *.so *.o
