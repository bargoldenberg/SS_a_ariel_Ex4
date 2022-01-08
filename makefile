all:  graph
graph: main.o Graph.a Graph.h Queue.a Queue.h List.a List.h
	gcc -Wall -g -o graph main.o Graph.a Queue.a List.a
Graph:Graph.a
Queue:Queue.a
List: List.a
List.a: List.o
	ar -rcs List.a List.o
Queue.a: Queue.o
	ar -rcs Queue.a Queue.o
Graph.a: Graph.o 
	ar -rcs Graph.a Graph.o
Graph.o: Graph.c Graph.h Queue.h List.h
	gcc -Wall -g -c Graph.c 
List.o: List.c List.h
	gcc -Wall -g -c List.c
Queue.o: Queue.c Queue.h
	gcc -Wall -g -c Queue.c
main.o: main.c Graph.h Queue.h List.h
	gcc -Wall -g -c main.c 

.PHONY: clean#.PHONY means that clean is not a file.
clean:
	rm -f *.o *.a  graph 