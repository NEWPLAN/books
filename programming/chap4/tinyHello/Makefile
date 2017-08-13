obj=TinyHelloWorld.o
src=TinyHelloWorld.c
res=TinyHelloWorld
srcipt=ld.script

#$@:$< $2 $3....[$^]
# gcc -o $@ $^
# $@ : 代表目标
# $< : 代表第一个依赖对象
# $^ : 代表所有依赖对象

all:$(res)
	@echo "make done";
	

$(obj):$(src)
	gcc -m32 -c -fno-builtin $< -o $@


$(res):$(obj)
	ld -m elf_i386 -static -T $(srcipt) -o $@ $^
	

	

	
.PHONY:clean

clean:
	rm -f $(obj) $(res)
	
	
#$(res):$(obj)
#ld -m elf_i386 -static -e nomain -o $@ $^
