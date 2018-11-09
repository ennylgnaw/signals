all: signals.o
	gcc -o a.out signals.o

signals.o: signals.c
	gcc -c signals.c

run:
	./a.out

clean:
	rm a.out
	rm *.o
