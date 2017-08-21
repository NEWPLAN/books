target=crack.exe
cc=gcc
LD=ld
arch=-m32
ldflags=-m elf_i386
src=crack.c
objs=crack.o
head=
all:$(target)

%.o:%.c $(head)
	$(cc) $(arch) -c -o $@ $<

$(target):$(objs)
	$(cc) $(arch) -o $@ $^

.PHONY:clean

clean:
	rm -f $(objs) $(target)