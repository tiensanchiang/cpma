all: inventory.out word.out

word.out: readline.o word.o
	gcc -o $@ $^

inventory.out: inventory.o readline.o
	gcc -o $@ $^

inventory.o: inventory.c
	gcc -Wall --std=c11 -c $^

word.o: word.c
	gcc -Wall --std=c11 -c $^

%o: %c %.h
	gcc -Wall --std=c11 -c $^