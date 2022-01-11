all: graph


#compiled file of main
main.o: main.c actions.c graph.c
	gcc -Wall -g -c main.c


graph: main.o
	gcc -Wall -g -o graph main.o


.PHONY: clean all
clean:
	rm -f *.o *.a *.so graph