#include "List.h"
#include <stdlib.h>
#include <stdio.h>

//------------------------------------------------
// Node implementation
//------------------------------------------------
typedef struct _node {
	int _data;
	struct _node* _next;
} Node;

Node* List_Node_alloc(int data,
				 Node* next) {
	Node* p= (Node*)malloc(sizeof(Node));
	p->_data= data;
	p->_next= next;
	return p;
}

void List_Node_free(Node* node) {
	free(node);
}
//------------------------------------------------



//------------------------------------------------
// List implementation
//------------------------------------------------
struct _List {
	Node* _head;
	size_t _size;
};

List* List_alloc() {
	List* p= (List*)malloc(sizeof(List));
	p->_head= NULL;
	p->_size= 0;
	return p;
}

void List_free(List* list) {
	if (list==NULL) return;
	Node* p1= list->_head;
	Node* p2;
	while(p1) {
		p2= p1;
		p1= p1->_next;
		List_Node_free(p2);
	}
	free(list);
}

size_t List_size(const List* list) {
	return list->_size;
}

double List_firstData(const List* list) {
	return list->_head->_data;
}

void List_insertFirst(List* list,
					  double data) {
	list->_head= List_Node_alloc(data,list->_head);
	++(list->_size);
}

void List_print(const List* list) {
	const Node* p= list->_head;
	while(p) {
		printf("(%d)->",p->_data);
		p= p->_next;
	}
	printf("|| size:%zu\n",list->_size);
}

int GetNode(List* l,int i){
	if(i>List_size(l)){
		return -1;
	}
	int x=0;
	Node* ptr = l->_head;
	while(x<i){
		ptr = ptr->_next;
		x++;
	}
	return ptr->_data;
}

//------------------------------------------------
