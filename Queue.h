#pragma once

#include <stdlib.h>

/********************************************************************************
 *
 * A Queue library.
 *
 * This library provides a Queue of ints data structure.
 *
 * 
 * 
 *
 ********************************************************************************/

/*
 * Queue represents a Queue data structure.
 */
struct _Queue;
typedef struct _Queue Queue;

/*
 * Allocates a new empty Queue.
 * It's the user responsibility to free it with List_free.
 */
Queue* Queue_alloc();

/*
 * Frees the memory and resources allocated to list.
 * If list==NULL does nothing (same as free).
 */
void Queue_free(Queue* q);

/*
 * Returns the number of elements in the list.
 */
size_t Queue_size(const Queue* q);

/*
 * Inserts an element in the begining of the list.
 */
void Queue_enqueue(Queue* q, int data);

int Queue_dequeue(Queue* q);
/*
 * Returns the list first data.
 */
int Queue_firstData(const Queue* q);

/*
 * Prints the list to the standard output.
 */
void Queue_print(const Queue* q);

int Queue_contains(Queue* q,int data);


