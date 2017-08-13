ARCHX=-m32
DYNAMEC=-fPIC -shared
CFLAGS=$(ARCHX) $(DYNAMEC)
TARGET=a1.so a2.so b1.so b2.so

all:$(TARGET)

a%.so:a%.c
	gcc $(CFLAGS) $^ -o $@

b%.so:b%.c a%.so 
	gcc $(CFLAGS) $^ -o $@ -Xlinker -rpath ./

main:main.c $(TARGET)
	gcc $(ARCHX) $^ -o $@ -Xlinker -rpath ./

.PHONY:clean

clean:
	rm -f $(TARGET) main


