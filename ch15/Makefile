all: justify.out

justify.out: justify.o word.o line.o
	gcc -Wall --std=c11 -o $@ $^

justify.o: justify.c
	gcc -Wall --std=c11 -c justify.c

%.o: %.c %.h
	gcc -Wall --std=c11 -c $^