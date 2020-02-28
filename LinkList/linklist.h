// linklist.h

#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef NOAN
#define NOAN -2147483648
#endif


typedef int ElementType;
struct linklistnode {
	ElementType data;
	struct linklistnode* next;
};
typedef struct linklistnode* LinkListNode;
typedef struct linklisthead {
	LinkListNode head;
} LinkListHead;
typedef LinkListHead* LinkList;

LinkList linklist_create(void);
LinkList linklist_copyfrom(ElementType*,int,int);
LinkListNode linklist_get(LinkList,int);
LinkListNode linklist_find(LinkList,ElementType);
LinkListNode linklist_insert(LinkList,ElementType,int);
ElementType linklist_delete(LinkList,int);
void linklist_traverse(LinkList,void (*)(ElementType*));
void linklist_clear(LinkList);

#endif