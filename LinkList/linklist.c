// linklist.c

#include "linklist.h"

// 检查链表是否存在
static bool linklist_exist(LinkList listhead) {
	if(listhead)
		return true;
	else {
		fprintf(stderr,"no linklist!\n");
		return false;
	}
}

// 创建一个节点
static LinkListNode node_create(ElementType elem) {
	LinkListNode tempNode=(LinkListNode)malloc(sizeof(struct linklistnode));
	tempNode->data=elem;
	tempNode->next=NULL;
	return tempNode;
}

// 建立空链表
LinkList linklist_create(void) {
	LinkList tempHead=(LinkList)malloc(sizeof(LinkListHead));
	tempHead->head=NULL;
	return tempHead;
}

// 从给定数组建立链表，[lo,hi)
LinkList linklist_copyfrom(ElementType* arr,int lo,int hi) {
	LinkList tempHead=linklist_create();
	LinkListNode tempNode=NULL,preNode=NULL;
	while(lo<hi) {
		tempNode=node_create(arr[lo]);
		if(tempHead->head)
			preNode->next=tempNode;
		else
			tempHead->head=tempNode;
		preNode=tempNode;
		lo++;
	}
	return tempHead;
}

// 获取第ind个元素的指针，失败返回NULL
LinkListNode linklist_get(LinkList listhead,int ind) {
	if(linklist_exist(listhead)) {
		int n=0;
		LinkListNode tempNode=listhead->head;
		while(tempNode) {
			n++;
			if(ind==n)
				return tempNode;
			else
				tempNode=tempNode->next;
		}
		return NULL;
	}
	return NULL;
}

// 按值查找最近的匹配项，失败返回NULL
LinkListNode linklist_find(LinkList listhead,ElementType elem) {
	if(linklist_exist(listhead)) {
		LinkListNode tempNode=listhead->head;
		while(tempNode) {
			if(tempNode->data==elem)
				return tempNode;
			else
				tempNode=tempNode->next;
		}
		return NULL;
	}
	return NULL;
}

// 将元素插入到第ind个位置，失败返回NULL，成功返回该位置的指针
LinkListNode linklist_insert(LinkList listhead,ElementType elem,int ind) {
	if(linklist_exist(listhead)) {
		if(ind<1)
			return NULL;
		else if(ind==1) {
			LinkListNode node=node_create(elem);
			node->next=listhead->head;
			listhead->head=node;
			return node;
		}
		else {
			LinkListNode tempNode=linklist_get(listhead,ind-1);
			if(tempNode) {
				LinkListNode node=node_create(elem);
				node->next=tempNode->next;
				tempNode->next=node;
				return node;
			}
			else
				return NULL;
		}
	}
	return NULL;
}

// 删除第ind个元素，返回该元素的值，失败返回NOAN
ElementType linklist_delete(LinkList listhead,int ind) {
	if(linklist_exist(listhead)) {
		if(ind<1)
			return NOAN;
		else if(ind==1) {
			if(listhead->head) {
				LinkListNode deleteNode=listhead->head;
				listhead->head=deleteNode->next;
				ElementType returnVal=deleteNode->data;
				free(deleteNode);
				return returnVal;
			}
			else
				return NOAN;
		}
		else {
			LinkListNode tempNode=linklist_get(listhead,ind-1);
			if(tempNode) {
				if(tempNode->next) {
					LinkListNode deleteNode=tempNode->next;
					tempNode->next=deleteNode->next;
					ElementType returnVal=deleteNode->data;
					free(deleteNode);
					return returnVal;
				}
				else
					return NOAN;
			}
			else
				return NOAN;
		}
	}
	return NOAN;
}

// 遍历链表，对每个元素作用函数fun
void linklist_traverse(LinkList listhead,void (*fun)(ElementType* eptr)) {
	if(linklist_exist(listhead)) {
		LinkListNode temp=listhead->head;
		while(temp) {
			fun(&(temp->data));
			temp=temp->next;
		}
	}
}

// 销毁链表
void linklist_clear(LinkList listhead) {
	if(linklist_exist(listhead)) {
		LinkListNode temp=listhead->head,deleteNode;
		while(temp) {
			deleteNode=temp;
			temp=temp->next;
			free(deleteNode);
		}
		free(listhead);
	}
}