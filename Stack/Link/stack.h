// stack.h

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef NOAN
#define NOAN -2147483648
#endif

typedef int ElementType;
typedef struct stacknode {
	ElementType data;
	struct stacknode* next;
} StackNode;
typedef StackNode* Stack;

Stack stack_create();
bool stack_isempty(Stack);
bool stack_push(Stack,ElementType);
ElementType stack_pop(Stack);
void stack_clear(Stack);

#endif