#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

//------------------------------------------------
// Node implementation
//------------------------------------------------
typedef struct _node {
	int _data;
	struct _node* _next;
} Node;

Node* QNode_alloc(int data, Node* next) {
	Node* p= (Node*)malloc(sizeof(Node));
	p->_data= data;
	p->_next= next;
	///_-_-_-_- check!!!

	return p;
}

void QNode_free(Node* node) {
	free(node);
}
//------------------------------------------------



//------------------------------------------------
// List implementation
//------------------------------------------------
typedef struct _Queue {
	Node* _head;
	size_t _size;
}Queue;

Queue* Queue_alloc() {
	Queue* p= (Queue*)malloc(sizeof(Queue));
	p->_head= NULL;
	p->_size= 0;
	return p;
}

void Queue_free(Queue* q) {
	if (q==NULL) return;
	Node* p1= q->_head;
	Node* p2;
	while(p1) {
		p2= p1;
		p1= p1->_next;
		QNode_free(p2);
	}
	free(q);
}

size_t Queue_size(const Queue* q) {
	return q->_size;
}

int Queue_firstData(const Queue* q) {
	return q->_head->_data;
}

void Queue_enqueue(Queue* q,int data) {

	q->_head= QNode_alloc(data,q->_head);
	++(q->_size);
}

int Queue_contains(Queue* q,int data){
	Node* ptr = q->_head;
	while(ptr){
		if(ptr->_data==data){
			return  1;
		}
		ptr = ptr->_next;
	}
	return 0;
}

// int Queue_dequeue(Queue* q){
// 	if(Queue_size(q) == 0){// Assuming -1 is NULL.
// 		return -1;
// 	} 
// 	else if(Queue_size(q) == 1){
// 		int data = q->_head ->_data;
// 		QNode_free(q->_head);
// 		--(q->_size);
// 		return data;
// 	}
// 	else if(Queue_size(q) == 2){
// 		Node* ptr = q->_head->_next;
// 		int data = ptr -> _data;
// 		q->_head->_next = NULL;
// 		QNode_free(ptr);
// 		--(q->_size);
// 		return data;
// 	}
// 	else{
// 		Node* ptr = q->_head;
// 		printf("DeQueue  > 3 , ptr = %d\n", ptr->_data);
// 		while(ptr->_next->_next && ptr->_data != 0){
// 			printf("ptr = %d\n",ptr->_data);
// 			ptr = ptr->_next;
// 		}
// 		printf("DeQueue 2 \n");
// 		Node* delete_node = ptr->_next;
// 		ptr->_next=NULL;
// 		int data = delete_node->_data;
// 		printf("DeQueue 3 \n");
// 		QNode_free(delete_node);
// 		--(q->_size);
// 		return data;
// 		}

// 	}

int Queue_dequeue(Queue* q){
	if(q->_size==0){
		printf("QUEUE IS EMPTY\n");
		return -1;
	}
	if(q->_size==1){
		int data = q->_head->_data;
		QNode_free(q->_head);
		q->_head=NULL;
		--(q->_size);
		return data;
	}
	Node* ptr = q->_head;
	while(ptr->_next->_next){
		ptr = ptr->_next;
	}
	Node* delete_node = ptr->_next;
	ptr->_next=NULL;
	int data = delete_node->_data;
	QNode_free(delete_node);
	--(q->_size);
	return data;
}






void Queue_print(const Queue* q) {
	const Node* p= q->_head;
	while(p) {
		printf("(%d)->",p->_data);
		p= p->_next;
	}
	printf("|| size:%zu\n",q->_size);
}

// int main(){
// 	Queue* q = Queue_alloc();
// 	for(int i=0;i<10;i++){
// 		Queue_enqueue(q,i);
// 	}
// 	Queue_print(q);
// 		for(int i=0;i<10;i++){
// 		Queue_dequeue(q);
// 	}	
// 	Queue_print(q);
// 	Queue_free(q);
// 	return 0;
// }

//------------------------------------------------
