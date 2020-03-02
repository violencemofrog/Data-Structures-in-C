// queue.h

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef DEFAULT_MAXSIZE
#define DEFAULT_MAXSIZE 5
#endif

#ifndef NOAN
#define NOAN -2147483648
#endif

typedef int ElementType;
typedef struct queuenode {
	ElementType* data;
	int size;// 队列最大容量加一（数组最大长度）
	int front;
	int rear;
} QueueNode;
typedef QueueNode* Queue;

Queue queue_create(int);
int queue_size(Queue);
bool queue_add(Queue,ElementType);
ElementType queue_delete(Queue);
void queue_clear(Queue);

#endif