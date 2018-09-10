all: inventory.out

inventory.out: inventory.o part.o menu.o
	gcc -Wall --std=c11 -o $@ $^

inventory.o: inventory.c
	gcc -Wall --std=c11 -c inventory.c

%.o: %.c %.h
	gcc -Wall --std=c11 -c $^