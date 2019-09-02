OBJS = add.o sub.o mul.o div.o
OBJS2 = add.h sub.h mul.h div.h

all: multiply arrays ages loops

multiply: multiply.o
	gcc -o multiply multiply.o

arrays: arrays.o
	gcc -o arrays arrays.o

ages: ages.o
	gcc -o ages ages.o

loops: loops.o
	gcc -o loops loops.o

multiply.o: multiply.c
	gcc -c multiply.c

arrays.o: arrays.c
	gcc -c arrays.c

ages.o: ages.c
	gcc -c ages.c

loops.o: loops.c
	gcc -c loops.c


clean:
	rm -rf loops ages arrays multiply *.o
