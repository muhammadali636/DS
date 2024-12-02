all: a2graph

a2graph: main.o graph_functions.o
	gcc -Wall -std=c99 -pedantic main.o graph_functions.o -o a2graph

main.o: main.c graph.h
	gcc -Wall -std=c99 -pedantic -c main.c -o main.o

graph_functions.o: graph_functions.c graph.h
	gcc -Wall -std=c99 -pedantic -c graph_functions.c -o graph_functions.o

clean:
	rm -f *.o a2graph
