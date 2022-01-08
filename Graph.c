#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"
#include "List.h"

#define Max 1000000 

//------------------------------------------------
// Node implementation
//------------------------------------------------
typedef struct _node {
	int _data;
	struct _node* _next;
} Node;

Node* Node_alloc(int data,
				 Node* next) {
	Node* p= (Node*)malloc(sizeof(Node));
	if(!p){
		printf("NO SPACE N");
	}
	p->_data= data;
	p->_next= next;
	return p;
}

void Node_free(Node* node) {
	free(node);
}


//------------------------------------------------
// Edge Implementation
//------------------------------------------------
typedef struct _edge {
	double _weight;
	int _src;
	int _dest;
	struct _edge* _next;
} Edge;

Edge* Edge_alloc(double weight,
				 int src, int dest, Edge* next) {
	Edge* p= (Edge*)malloc(sizeof(Edge));
	if(!p){
		printf("NO SPACE E");
	}
	p->_weight= weight;
	p->_src= src;
	p->_dest= dest;
	p->_next= next;
	return p;
}

void Edge_free(Edge* edge) {
	free(edge);
}


//------------------------------------------------
// Graph implementation
//------------------------------------------------
typedef struct _graph {
	Node* _headv;
	Edge* _heade;
	size_t _size;
	size_t _esize;
}Graph;

Graph* Graph_alloc() {
	Graph* p= (Graph*)malloc(sizeof(Graph));
	if(!p){
		printf("NO SPACE G");
	}
	p->_headv= NULL;
	p->_heade= NULL;
	p->_size= 0;
	p->_esize=0;
	return p;
}

Node* getNode(const Graph* g, int id) {
    Node* ptr = g->_headv;
    while(ptr){
		if(ptr->_data==id){
			return ptr;
		}
        ptr = ptr->_next;
    }
    return NULL;
}

void Graph_free(Graph* g) {
	if (g==NULL) return;
	Node* p1= g->_headv;
	Node* p2;
	while(p1) {
		p2= p1;
		p1 = p1->_next;
		Node_free(p2);
	}
	g->_size=0;
	Edge* ep1= g->_heade;
	Edge* ep2;
	while(ep1){
		ep2 = ep1;
		ep1 = ep1->_next;
		Edge_free(ep2);
	}
	g->_esize=0;
	free(g);
}

size_t Graph_size(const Graph* g) {
	return g->_size;
}

Node* V_firstNode(const Graph* g) {
	return g->_headv;
}

Edge* E_firstEdge(const Graph* g) {
	return g->_heade;
}

void Graph_insertNode(Graph* g, int data) {
	Node* ptr = getNode(g,data);
	//Delete all out edges from node
	if(ptr){
		Edge** tmp =NULL;
		Edge* ep = g->_heade;
		while(ep)
		{
			if(ep->_next==NULL){
				
				//Graph_print(g);
				break;
			}
			if(g->_heade->_src==data){
				tmp = &(g->_heade->_next);
				Edge* deletedEdge =g->_heade;
				g->_heade=g->_heade->_next;
				Edge_free(deletedEdge);
				g->_esize--;
				ep = g->_heade;						
			}else if(ep->_next->_src==data){	
				Edge* deletedEdge = ep->_next;	
				if(deletedEdge->_next==NULL){
					ep->_next=NULL;
					Edge_free(deletedEdge);
					g->_esize--;
					break;
				}else{	
					ep->_next=deletedEdge->_next;
					Edge_free(deletedEdge);
					g->_esize--;
					continue;
				}
			}
			if(tmp){
				ep = *tmp;
				//printf("TMP SRC: %d\n",*(tmp)->_src);
				tmp = NULL;
				
			}else{
				ep = ep->_next;
			}
		}
	}else{
		g->_headv= Node_alloc(data,g->_headv);
		++(g->_size);
	}
}


void Graph_insertEdge(Graph* g, int src, int dest, double weight){
	g->_heade= Edge_alloc(weight,src,dest,g->_heade);
	++(g->_esize);
}

void Graph_print(const Graph* g) {
	const Node* p= g->_headv;
	printf("Nodes:\n");
	while(p) {
		printf("(%d)->",p->_data);
		p= p->_next;
	}
	printf("|| size:%zu\n",g->_size);
	const Edge* pe = g->_heade;
	printf("Edges:\n");
		while(pe) {
		printf("(src: %d,dest: %d,weight: %.2f)->",pe->_src,pe->_dest,pe->_weight);
		pe= pe->_next;
	}
	printf("|| edge size:%zu\n",g->_esize);
}

						


Node* getNodeIndex(const Graph* g, int index) {
    Node* ptr = g->_headv;
	int i =0;
	if(index > Graph_size(g)){
		return NULL;
	}
	else if(index == i){return ptr;}
	else{
		while(i<index){
	        ptr = ptr->_next;
			i++;
    	}
    	return ptr;
	}
}

int getMaxID(const Graph* g){
	Node* ptr = g->_headv;
	int max_id=-1;
	while(ptr){
		if(ptr->_data>max_id){
			max_id=ptr->_data;
		}
		ptr=ptr->_next;
	}
	return max_id;
}

Edge* getEdge(const Graph* g, int src, int dest) {
	if(src == dest){return NULL;}
	else{
		// printf("Got into 'getEdge': src = %d, dest = %d\n",src,dest);
		Edge* ptr = g->_heade;
    	while(ptr){
			// printf("ptr -> dest: %d\n",ptr->_dest);
			if(ptr->_src == src && ptr -> _dest == dest){
				return ptr;
				break;
			}
			ptr = ptr->_next;		 
    	}
		// printf("got out of while\n");
    	return 	NULL;
	}
}



void deleteNode(Graph* g, int id){
	if(!getNode(g,id)){
		return;
	}
	Node* ptr = g->_headv;
	Edge* tmp =NULL;
    while(ptr){
		if(ptr->_data==id)
		{
			Node* deletednode = ptr;
			g->_headv = ptr->_next;
			Node_free(deletednode);
			g->_size--;
			break;
		}
		else if(ptr->_next->_data==id)
		{
			
			Node* deletednode =ptr->_next;
			if(deletednode->_next==NULL)
			{
				ptr->_next=NULL;
				Node_free(deletednode);
				g->_size--;
				break;
			}
			else
			{
				ptr->_next=ptr->_next->_next;
				Node_free(deletednode);
				g->_size--;
				break;
			}
		}
	
	
        ptr = ptr->_next;		
    }
	Edge* ep = g->_heade;
	while(ep)
	{
		if(ep->_next==NULL){
			//Graph_print(g);
			break;
		}
		if(g->_heade->_dest==id||g->_heade->_src==id){
			tmp = (g->_heade->_next);
			Edge* deletedEdge =g->_heade;
			g->_heade=g->_heade->_next;
			Edge_free(deletedEdge);
			g->_esize--;
			ep = g->_heade;						
		}else if(ep->_next->_src==id||ep->_next->_dest==id){	
			Edge* deletedEdge = ep->_next;	
			if(deletedEdge->_next==NULL){
				ep->_next=NULL;
				Edge_free(deletedEdge);
				g->_esize--;
				break;
			}else{
				ep->_next=deletedEdge->_next;
				Edge_free(deletedEdge);
				g->_esize--;
				continue;
			}
		}
		if(tmp){
			ep = tmp;
			//printf("TMP SRC: %d\n",*(tmp)->_src);
			tmp = NULL;
			
		}else{
			ep = ep->_next;
		}
	}
}

double min(double a, double b){
	if(a <0){
		a=Max;
	}
	if(b<0){
		b=Max;
	}
	if(a<b){return a;}
	else{return b;}
}

//------------------------------------------------
// Function implementation
//------------------------------------------------

int shortestPath(const Graph* g, int id1, int id2){
	double distance[getMaxID(g)+1];
	int prev[getMaxID(g)+1];
	Queue* q = Queue_alloc();
	for(int i=0;i<Graph_size(g);i++){
		Node* curr = getNodeIndex(g,Graph_size(g)-i-1);
		if(curr){
			if(curr->_data==id1){
				distance[curr->_data]=0;
				Queue_enqueue(q,curr->_data);
			}else{
				distance[curr->_data]=Max;
			}
			int a = curr->_data;
			prev[a]=0;
		
		}else{
			continue;
		}
	}
		while(Queue_size(q)){
			Edge* e;
			int smallest = Queue_dequeue(q);
			if(smallest==id2){
				while(prev[smallest]){
					smallest = prev[smallest];
				}
			}else if(distance[smallest]==Max){
				break;
			}else{
				for(int j=0;j<Graph_size(g);j++){
					Node* dest = getNodeIndex(g,j);
					e = getEdge(g,smallest,dest->_data);
					if(e){	
						double d = distance[smallest] + e->_weight;
						if(d<distance[e->_dest]){
							distance[e->_dest]=d;
							prev[e->_dest]=smallest;
							if(Queue_contains(q,e->_dest) == 0){
								Queue_enqueue(q,e->_dest);
							}
						}
						
					}else{
						continue;
					}
				}

			}
		}
	
	if(distance[id2]==Max){
		Queue_free(q);
		return -1;
	}else{
		Queue_free(q);
		return distance[id2];
	}
}

 int TSP(Graph *g,List* l){
	 if(List_size(l)==0){
		 return -1;
	 }else if(List_size(l)==1){
		 return 0;
	 }else if(List_size(l)==2){
		 int min=Max;
		 for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				if(i==j){
					continue;
				}
				int ithnode = GetNode(l,i);
				int jthnode = GetNode(l,j);
				int first = shortestPath(g,ithnode,jthnode);
				if(first ==-1){
					continue;
				}
				int dist=first;
				if(dist<min){
					min = dist;
				}
			}
		 }
		 if(min==Max){
			 return -1;
		 }else{
		 	return min;
		 }
	 }else if(List_size(l)==3){
		 int min=Max;
		 for(int i=0;i<3;i++){
			 for(int j=0;j<3;j++){
				 for(int x =0;x<3;x++){
					if(x==j||j==i||x==j||i==x){
						continue;
					}
					int ithnode = GetNode(l,i);
					int jthnode = GetNode(l,j);
					int xthnode = GetNode(l,x);
					int first = shortestPath(g,ithnode,jthnode);
					int second = shortestPath(g,jthnode,xthnode);
					if(first==-1||second==-1){
						continue;
					}
					int dist = first+second;
					if(dist<min){
					min = dist;
				}
				 }
			 }
		 }if(min==Max){
			 return -1;
		 }else{
		 	return min;
		 }
	 }else if(List_size(l)==4){
		 int min=Max;
		 for(int i =0;i<4;i++){
			 for(int j=0;j<4;j++){
				 for(int x=0;x<4;x++){
					 for(int k=0;k<4;k++){
						 if(i==k||i==j||i==x||j==x||k==x||k==j){
							 continue;
						 }
						int ithnode = GetNode(l,i);
						int jthnode = GetNode(l,j);
						int xthnode = GetNode(l,x);
						int kthnode = GetNode(l,k);
						int first = shortestPath(g,ithnode,jthnode);
						int second = shortestPath(g,jthnode,xthnode);
						int third = shortestPath(g,xthnode,kthnode);
						if(first==-1||second==-1||third==-1){
							continue;
						}
						int dist = first+second+third;
						if(dist<min){
						min = dist;
						}
					 }
				 }
			 }
		 }
		 if(min==Max){
			 return -1;
		 }else{
		 	return min;
		 }
	 }else if(List_size(l)==5){
		int min=Max;
		 for(int i =0;i<5;i++){
			 for(int j=0;j<5;j++){
				 for(int x=0;x<5;x++){
					 for(int k=0;k<5;k++){
						 for(int f = 0;f<5;f++){
							if(i==k||i==j||i==x||j==x||k==x||k==j||k==f||x==f||j==f||i==f){
								continue;
							}
							int first = shortestPath(g,GetNode(l,i),GetNode(l,j));
							int second = shortestPath(g,GetNode(l,j),GetNode(l,x));
							int third = shortestPath(g,GetNode(l,x),GetNode(l,k));
							int fourth = shortestPath(g,GetNode(l,k),GetNode(l,f));
							if(first==-1||second==-1||third==-1||fourth==-1){
								continue;
							}
							int dist = first+second+third+fourth;
							if(dist<min){
							min = dist;
							}
						}
					}
				}
			 }
		 }
		 if(min==Max){
			 return -1;
		 }else{
		 	return min;
		 };
	 }else if(List_size(l)==6){
		int min=Max;
		 for(int i =0;i<6;i++){
			 for(int j=0;j<6;j++){
				 for(int x=0;x<6;x++){
					 for(int k=0;k<6;k++){
						 for(int f = 0;f<6;f++){
						 	for(int z=0;z<6;z++){
								if(i==k||i==j||i==x||j==x||k==x||k==j||k==f||x==f||j==f||i==f||z==f||z==k||z==x||z==k||z==i){
									continue;
								}
								int first = shortestPath(g,GetNode(l,i),GetNode(l,j));
								int second = shortestPath(g,GetNode(l,j),GetNode(l,x));
								int third = shortestPath(g,GetNode(l,x),GetNode(l,k));
								int fourth = shortestPath(g,GetNode(l,k),GetNode(l,f));
								int fifth = shortestPath(g,GetNode(l,f),GetNode(l,z));
								if(first==-1||second==-1||third==-1||fourth==-1||fifth==-1){
									continue;
								}
								int dist = first+second+third+fourth+fifth;
								if(dist<min){
								min = dist;
								}
							}
						}
					 }
				 }
			 }
		 }
		 if(min==Max){
			 return -1;
		 }else{
		 	return min;
		 }
	 }
	 return 0;
 }
