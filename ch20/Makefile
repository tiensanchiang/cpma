all: viewmem.out floatunion.out

viewmem.out: viewmem.o
	gcc -o $@ $^

floatunion.out: floatunion.o
	gcc -o $@ $^

%.o: %.c
	gcc -Wall --std=c11 -O3 -c $^