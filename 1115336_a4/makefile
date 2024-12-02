all: a4

a4: main.o graph_functions.o
	gcc -Wall -std=c99 -pedantic main.o graph_functions.o -o a4

main.o: main.c graph.h
	gcc -Wall -std=c99 -pedantic -c main.c -o main.o

graph_functions.o: graph_functions.c graph.h
	gcc -Wall -std=c99 -pedantic -c graph_functions.c -o graph_functions.o

clean:
	rm -f *.o a2graph
