all: stackclient.out queueclient.out

stackclient.out: stackclient.o stack_arr.o
	gcc -o $@ $^

queueclient.out: queueclient.o queue_ll.o
	gcc -o $@ $^

stackclient.o: stackclient.c
	gcc -Wall --std=c11 -O3 -c $^

%.o: %.c
	gcc -Wall --std=c11 -O3 -c $^