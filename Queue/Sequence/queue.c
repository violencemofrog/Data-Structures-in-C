// queue.c

#include "queue.h"

// 判断队列是否存在
static bool queue_exist(Queue queue) {
	if(queue)
		return true;
	else {
		fprintf(stderr,"no queue!\n");
		return false;
	}
}

// 给定最大容量建立队列（不能小于默认容量）
Queue queue_create(int maxsize) {
	maxsize=maxsize>DEFAULT_MAXSIZE?maxsize:DEFAULT_MAXSIZE;
	Queue temp=(Queue)malloc(sizeof(QueueNode));
	temp->size=maxsize+1;// 有一个位置不存数据
	temp->data=(ElementType*)malloc(sizeof(ElementType)*(temp->size));
	temp->rear=temp->front=0;
	return temp;
}

// 返回队列当前元素数量（不存在队列返回-1）
int queue_size(Queue queue) {
	if(queue_exist(queue)) {
		if(queue->front>=queue->rear)
			return (queue->front)-(queue->rear);
		else
			return queue->size-queue->rear+queue->front;
	}
	else
		return -1;
}

// 入队，成功返回true
bool queue_add(Queue queue,ElementType elem) {
	if(queue_exist(queue)&&queue_size(queue)!=queue->size-1) {
		queue->data[queue->front]=elem;
		queue->front=(queue->front==queue->size-1)?0:queue->front+1;
	}
	return false;
}

// 出队（队列不存在或者没有元素返回NOAN
ElementType queue_delete(Queue queue) {
	if(queue_exist(queue)&&queue_size(queue)!=0) {
		ElementType temp=queue->data[queue->rear];
		queue->rear=(queue->rear==queue->size-1)?0:queue->rear+1;
	}
	return NOAN;
}

// 销毁队
void queue_clear(Queue queue) {
	if(queue) {
		if(queue->data)
			free(queue->data);
		free(queue);
	}
}