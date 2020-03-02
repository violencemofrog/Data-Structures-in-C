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

// 创建节点
static QueueNode* node_create(Element elem) {
	QueueNode* temp=(QueueNode*)malloc(sizeof(QueueNode));
	temp->data=elem;
	temp->next=NULL;
	return temp;
}

// 建立队列
Queue queue_create(void) {
	Queue temp=(Queue)malloc(sizeof(QueueHead));
	temp->size=0;
	temp->front=temp->rear=NULL;
	return temp;
}

// 返回当前队列元素个数（不存在返回-1）
int queue_size(Queue queue) {
	if(queue_exist(queue))
		return queue->size;
	return -1;
}

// 入队（成功返回true）
bool queue_add(Queue queue,Element elem) {
	if(queue_exist(queue)) {
		QueueNode* addNode=node_create(elem);
		if(queue->size==0)
			queue->front=queue->rear=addNode;
		else {
			queue->rear->next=addNode;
			queue->rear=addNode;
		}
		queue->size++;
		return true;
	}
	return false;
}

// 出队
Element queue_delete(Queue queue) {
	if(queue_exist(queue)&&(0!=queue_size(queue))) {
		QueueNode* deleteNode=queue->front;
		Element temp=deleteNode->data;
		queue->front=deleteNode->next;
		free(deleteNode);
		queue->size--;
		return temp;
	}
	return NOAN;
}

// 销毁栈
void queue_clear(Queue queue) {
	if(queue) {
		QueueNode* temp=queue->front;
		QueueNode* deleteNode;
		while(temp) {
			deleteNode=temp;
			temp=deleteNode->next;
			free(deleteNode);
		}
		free(queue);
	}
}
