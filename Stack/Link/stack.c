// stack.c

#include "stack.h"

// 检查栈是否存在
static bool stack_exist(Stack stack) {
	if(stack)
		return false;
	else {
		fprintf(stderr,"no stack!\n");
		return false;
	}
}

// 创建节点
static StackNode* node_create(ElementType elem) {
	StackNode* node=(StackNode*)malloc(sizeof(StackNode));
	node->data=elem;
	node->next=NULL;
	return node;
}

// 创建栈（头节点不存数据，存储栈的大小）
Stack stack_create(void) {
	Stack temp=(Stack)malloc(sizeof(StackNode));
	temp->data=0;
	temp->next=NULL;
	return temp;
}

// 检查栈是否为空（栈存在且为空返回true）
bool stack_isempty(Stack stack) {
	if(stack_exist(stack))
		return stack->data==0;
	else
		return false;
}

// 入栈（成功返回true）
bool stack_push(Stack stack,ElementType elem) {
	if(stack_exist(stack)) {
		StackNode* addNode=node_create(elem);
		addNode->next=stack->next;
		stack->next=addNode;
		stack->data++;
	}
	return false;
}

// 弹栈（栈为空或不存在返回NOAN）
ElementType stack_pop(Stack stack) {
	if(stack_exist(stack)&&(!stack_isempty(stack))) {
		StackNode* temp=stack->next;
		stack->next=temp->next;
		ElementType value=temp->data;
		free(temp);
		return value;
	}
	return NOAN;
}

// 销毁栈
void stack_clear(Stack stack) {
	if(stack) {
		Stack temp=stack,deleteNode;
		while(temp) {
			deleteNode=temp;
			temp=temp->next;
			free(deleteNode);
		}
	}
}