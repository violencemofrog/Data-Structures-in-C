// list.h

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef DEFAULT_MAXSIZE
#define DEFAULT_MAXSIZE 10
#endif

typedef int ElementType;
typedef struct listnode {
	int maxSize;
	int lastIndex;
	ElementType* data;
} ListNode;
typedef ListNode* List;

List list_create(int);
int list_find(List,ElementType);
List list_copyfrom(ElementType*,int,int);
bool list_insert(List,ElementType,int);
bool list_delete(List,int);
void list_traverse(List list,void (*fun)(ElementType* eptr));
void list_clear(List);

#endif