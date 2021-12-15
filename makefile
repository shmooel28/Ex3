CC = gcc
FLAGS= -Wall -g
all: stringProg
stringProg: string.o
	$(CC) $(FLAGS) -o stringProg string.o
string.o: string.c
	$(CC) $(FLAGS) -c string.c
.PHONY: clean all
clean:
	rm -f *.o *.a stringProg