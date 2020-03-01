// stack.h

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef DEFAULT_MAXSIZE
#define DEFAULT_MAXSIZE 10
#endif

#ifndef NOAN
#define NOAN -2147483648
#endif

typedef int ElementType;
typedef struct stacknode {
	ElementType* data;
	int size;// data数组的大小
	int top;// 栈顶元素下标（初始为-1）
} StackNode;
typedef StackNode* Stack;

Stack stack_create(int);
bool stack_isempty(Stack);
bool stack_isfull(Stack);
bool stack_push(Stack,ElementType);
ElementType stack_pop(Stack);
void stack_clear(Stack);
#endif