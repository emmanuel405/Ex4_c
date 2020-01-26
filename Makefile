CC = gcc
OBJECTS_MAIN_TXTFIND = main.o trie.o
FLAGS= -Wall -g

all:      
trie.o: trie.c trie.h
        $(CC) $(FLAGS) -fPIC -c trie.c
main.o: main.c trie.h
        $(CC) $(FLAGS) -fPIC -c main.c 

.PHONY: clean all

clean:
        rm -f *.o  *.out isort txtfind