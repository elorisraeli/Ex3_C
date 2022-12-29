CC=gcc
FLAGS = -Wall

all: isort txtfind

isort: isort.o
	$(CC) $(FLAGS) -o isort isort.o

txtfind: txtfind.o
	$(CC) $(FLAGS) -o txtfind txtfind.o

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c

.PHONY: clean all

clean: 
	rm *.o isort txtfind