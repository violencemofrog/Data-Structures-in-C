// stack.c

#include "stack.h"

// 检查栈是否存在
static bool Stack_exist(Stack stack) {
	if(stack)
		return true;
	else {
		fprintf(stderr,"no stack");
		return false;
	}
}

// 给定容量创建栈（不可小于默认容量）
Stack stack_create(int maxsize) {
	maxsize=(DEFAULT_MAXSIZE>maxsize)?DEFAULT_MAXSIZE:maxsize;
	Stack temp=(Stack)malloc(sizeof(StackNode));
	temp->top=-1;
	temp->size=maxsize;
	temp->data=(ElementType*)malloc(sizeof(ElementType)*maxsize);
	return temp;
}

// 检查栈是否为空（存在且为空返回true）
bool stack_isempty(Stack stack) {
	if(Stack_exist(stack))
		return	stack->top==-1;
	return false;
}

// 检查栈是否满了（存在且存满返回true）
bool stack_isfull(Stack stack) {
	if(Stack_exist(stack))
		return stack->top==stack->size-1;
	else
		return false;
}

// 入栈（成功返回true）
bool stack_push(Stack stack,ElementType elem) {
	if(Stack_exist(stack)&&!(stack_isfull(stack))) {
		stack->top++;
		stack->data[stack->top]=elem;
	}
	return false;
}

// 弹栈（失败返回NOAN）
ElementType stack_pop(Stack stack) {
	if(Stack_exist(stack)&&!(stack_isempty(stack))) {
		ElementType temp=stack->data[stack->top];
		stack->top--;
		return temp;
	}
	return NOAN;
}


// 销毁栈
void stack_clear(Stack stack) {
	if(stack) {
		if(stack->data)
			free(stack->data);
		free(stack);
	}
}