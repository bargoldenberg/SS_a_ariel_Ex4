#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Queue.h"
#include "List.h"
#define A 65
#define n 110
#define B 66
#define D 68
#define S 83
#define T 84

int fromCharToInt(char c){
    return ((int) c-48);
}


int main()
{
    int FLAG =0;
    char input = 0;
    Graph* graph = NULL;
    while(input != '\n')
    {   
        if(!FLAG){
            scanf("%c",&input);
        }
        if(input == A) //ascii[A] = 65
        {
            if(graph){
                Graph_free(graph);
                FLAG=0;
            }
            graph = Graph_alloc();
            int size = 0;
            scanf("%d",&size);
            for(int i=0; i<size; i++){
                Graph_insertNode(graph,i);
            }
        }
        while(input == n){ // ascii[n] = 110
            FLAG =1;
            int id = 0;
            int dest = 0;
            int weight = 0;
            scanf("%d",&id);
            scanf("%c",&input);
            scanf("%c",&input);
            Node* tmp = getNode(graph,id);
            if(tmp){
                Graph_insertNode(graph,id);
            }
            //char charid = '0'+id;
            while(input >= 48 && input <= 57){
                dest =fromCharToInt(input);
                scanf("%d",&weight);
                Graph_insertEdge(graph,id,dest, weight);
                scanf("%c",&input);
                scanf("%c",&input);
            }
        }

        if(input == B){  //ascii[B] = 66
            FLAG =1;
            int id = 0;
            int dest = 0;
            int weight = 0;
            scanf("%d",&id);
            /**
             * Make new Node --> ID.
             */
            Graph_insertNode(graph,id);
           // Graph_print(graph);
            scanf("%c",&input);
            scanf("%c",&input);
            while(input >= 48 && input <= 57){
                dest = fromCharToInt(input);
                scanf("%d",&weight);
                /**
                 * Here we will do function that will add edge to node "id". and reapet this
                 */
                Graph_insertEdge(graph,id,dest,weight);
                scanf("%c",&input);
                scanf("%c",&input);
            }
        }
        if(input == D){  // ascii[D] = 68
            FLAG =1;
            int id =0;
            scanf("%d",&id);
            /**
             * Here we will delete node "id" from our graph.
             */
            deleteNode(graph,id);
            scanf("%c",&input);
            scanf("%c",&input);
        }
        if(input == S){  // ascii[S] = 83
            /**
             * Here we will check the shortest path from source to destination.
             */
            int source = 0;
            int destination = 0;
            scanf("%d",&source);
            scanf("%d",&destination);
            /**
             * dijkstra  Function Here int shortestPath(int id1, int id2);
             */
            printf("Dijsktra shortest path: %d \n",shortestPath(graph,source,destination));
            scanf("%c",&input);
            scanf("%c",&input);           
        }
         if(input == T){ 

            FLAG=1;
             //Graph_print(graph);
              // ascii[T] = 84
            /**
             * TSP algorithm // k <= 6.
             */
            int size = 0;
            scanf("%d",&size);
            List* l = List_alloc();
            int add = 0;
            for(int i=0; i<size; i++){
                scanf("%d", &add);
                List_insertFirst(l,add);
            }
            printf("TSP shortest path: %d \n",TSP(graph,l));
            /**
             * Tsp algorithm - int* tsp(int ids[]); (return pointer to an array - all the nodes {dont mind the order}).
             * Maybe an dynamic algorithm will be the best here -- 6! permutations
             */
            //printf("hi3\n");
            List_free(l);
            //printf("hi4\n");
            scanf("%c",&input);
            scanf("%c",&input); 
        }
     }


    //Graph_print(graph);
    Graph_free(graph);
}