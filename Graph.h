#pragma once
#include <stdlib.h>
#include "Queue.h"
#include "List.h"

/********************************************************************************
 *
 * A Graph library.
 *
 * This library implements a Graph data structure containing a list of nodes and edges (E and V) .
 *
 *
 ********************************************************************************/

/*
 * Graph represents a Graph data structure.
 */
typedef struct _graph Graph;
typedef struct _node Node;
typedef struct _edge Edge;

/*
 * Allocates a new empty Graph.
 * It's the user responsibility to free it with Graph_free.
 */
Graph* Graph_alloc();

/*
 * Frees the memory and resources allocated to g.
 * If list==NULL does nothing (same as free).
 */

Node* getNode(const Graph* g, int id);

void Graph_free(Graph* g);

/*
 * Returns the number of nodes in the Graph.
 */
size_t Graph_size(const Graph* g);

/*
 * Inserts an node in the begining of the node list.
 */
void Graph_insertNode(Graph* g, int data);

/*
* Inserts an edge in the begining of the edge list
*/
void Graph_insertEdge(Graph* g, int src, int dest, double weight);
/*
 * Returns the node list first node.
 */
Node* V_firstNode(const Graph* g);
/*
 * Returns the edge list first edge.
 */
Edge* E_firstEdge(const Graph* g);
/*
 * Prints the list to the standard output.
 */
void Graph_print(const Graph* g);

/*
 * Checks if two lists have the same elements
 * returns 0 if not and any other number if yes
 */
// int List_equal(const List* list1, const List* list2);

/*
 * Clones the given list. 
 * It's the user responsibility to free it with List_free.
 */
// List* List_clone(const List* list);

/**
 *  _________Task Algorithms:___________
 */
/*
 * For A - create a new graph.
 * then using Graph_insertEdge to add edges.
 */
void MakeGraph(Node* Head);
/*
 * For B - adding a new node to the graph.
 */
void addNode(Node* Head);
/*
 * For D - delete node from the graph
 */
void deleteNode(Graph* g,int id);
/*
 * For S -
 * Here we will check the shortest path from source to destination.
 * dijkstra  Function Here int shortestPath(int source, int destination);
 */
int shortestPath(const Graph* g, int id1, int id2);
/*
 * For T -
 * Tsp algorithm - int* tsp(int ids[]); (return pointer to an array - all the nodes {dont mind the order}).
 * Maybe a dynamic algorithm will be the best here -- 6! permutations
 */
int TSP(Graph* g, List* l);