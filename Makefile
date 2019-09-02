OBJS = add.o sub.o mul.o div.o
OBJS2 = add.h sub.h mul.h div.h

all: multiply arrays ages loops

multiply: multiply.c
	gcc -o multiply multiply.c

arrays: arrays.c
	gcc -o arrays arrays.c

ages: ages.c
	gcc -o ages ages.c

loops: loops.c
	gcc -o loops loops.c

clean:
	rm -rf loops ages arrays multiply
