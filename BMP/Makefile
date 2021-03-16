CFLAGS=-g -c -Wall -Wall -Wextra -Werror -Iinclude
all: BMP

BMP: obj/main.o obj/bmp.o
	gcc obj/main.o obj/bmp.o -o BMP

obj:
	mkdir obj
obj/main.o: src/main.c | obj
	gcc $(CFLAGS) src/main.c -o obj/main.o

obj/bmp.o: src/bmp.c include/bmp.h | obj
	gcc $(CFLAGS) src/bmp.c -o obj/bmp.o

clean:
	rm -rf obj BMP