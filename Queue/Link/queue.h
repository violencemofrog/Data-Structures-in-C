// queue.h

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef NOAN
#define NOAN -2147483648
#endif

typedef int Element;
typedef struct queuenode {
	Element data;
	struct queuenode* next;
} QueueNode;
typedef struct queuehead {
	int size;
	QueueNode* front;
	QueueNode* rear;
} QueueHead;
typedef QueueHead* Queue;

Queue queue_create();
int queue_size(Queue);
bool queue_add(Queue,Element);
Element queue_delete(Queue);
void queue_clear(Queue);

#endif