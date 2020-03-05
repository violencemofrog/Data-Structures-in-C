// traverse.c

#include "binarytree.h"

// 前序遍历
void tree_preordertraverse(TreeNode root,void (*fun)(Node* nodeptr)) {
	if(root) {
		fun(&root);
		tree_preordertraverse(root->left,fun);
		tree_preordertraverse(root->right,fun);
	}
}

// 中序遍历
void tree_inordertraverse(TreeNode root,void (*fun)(Node* nodeptr)) {
	if(root) {
		tree_inordertraverse(root->left,fun);
		fun(&root);
		tree_inordertraverse(root->right,fun);
	}
}

void tree_postordertraverse(TreeNode root,void (*fun)(Node* nodeptr)) {
	if(root) {
		tree_postordertraverse(root->left,fun);
		tree_postordertraverse(root->right,fun);
		fun(&root);
	}
}

/* 层序遍历 */
/* define queue */
typedef struct queuenode {
	Node* treenode;
	struct queuenode* next;
} QueueNode;
typedef struct queue {
	int size;
	QueueNode* front;
	QueueNode* rear;
};
typedef struct queue* Queue;

static Queue queue_create(void) {
	Queue temp=(Queue)malloc(sizeof(struct queue));
	temp->size=0;
	temp->front=temp->rear=NULL;
	return temp;
}

static void queue_push(Queue queue,Node* nodeptr) {
	if(!nodeptr)
		return;
	QueueNode* temp=(QueueNode*)malloc(sizeof(struct queuenode));
	temp->next=NULL;
	temp->treenode=nodeptr;

	if(queue->size==0)
		queue->front=queue->rear=temp;
	else {
		queue->rear->next=temp;
		queue->rear=temp;
	}
	queue->size++;
}

static Node* queue_pop(Queue queue) {
	if(queue->size!=0) {
		Node* temp=queue->front->treenode;
		QueueNode* deleteNode=queue->front;
		queue->front=deleteNode->next;
		free(deleteNode);
		queue->size--;
		return temp;
	}
	return NULL;
}

static void queue_clear(Queue queue) {
	if(queue) {
		QueueNode* temp=queue->front,* deleteNode;
		while(temp) {
			deleteNode=temp;
			temp=deleteNode->next;
			free(deleteNode);
		}
		free(queue);
	}
}
/* end define */

// 层序遍历
void tree_levelordertraverse(TreeNode root,void (*fun)(Node* nodeptr)) {
	if(root) {
		Queue myQueue=queue_create();
		queue_push(myQueue,root);
		while(myQueue->size) {
			Node* temp=queue_pop(myQueue);
			fun(temp);
			queue_push(myQueue,temp->left);
			queue_push(myQueue,temp->right);
		}
		queue_clear(myQueue);
	}
}
/* 层序遍历 */