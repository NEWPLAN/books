target=RunSosimple.exe

all:$(target)

%.exe:%.c
	gcc -m32 $^ -o $@ -ldl

runso:runso.c
	gcc -m32 runso.c -o runso -ldl

.PHONY:clean

clean:
	rm -f $(target) runso

