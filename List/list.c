// list.c

#include "list.h"

// 检验list是否存在（存在返回true）
static bool list_exist(List list) {
	if(list)
		return true;
	else {
		fprintf(stderr,"no list!\n");
		return false;
	}
}

// 倍增式扩容
static void list_expand(List list) {
	if(list->lastIndex=list->maxSize-1) {
		ElementType* oldData=list->data;
		list->maxSize*=2;
		list->data=(ElementType*)malloc(sizeof(ElementType)*list->maxSize);
		for(int i=0;i<=list->lastIndex;i++)
			list->data[i]=oldData[i];
		free(oldData);
	}
}

// 给出线性表长度（不可小于默认长度），建立线性表
List list_create(int maxsize) {
	maxsize=(maxsize<DEFAULT_MAXSIZE)?DEFAULT_MAXSIZE:maxsize;
	List tempList=(List)malloc(sizeof(ListNode));
	tempList->maxSize=maxsize;
	tempList->lastIndex=-1;
	tempList->data=(ElementType*)malloc(sizeof(ElementType)*maxsize);
	return tempList;
}

// 查找elem元素，返回匹配项最大的下标，找不到或list不存在返回-1
int list_find(List list,ElementType elem) {
	if(list_exist(list)) {
		for(int i=list->lastIndex;i>=0;i--)
			if(elem==list->data[i])
				return i;
			else
				continue;
	}
	return -1;
}

// 以数组来初始化线性表 [lo,hi)
List list_copyfrom(ElementType* arr,int lo,int hi) {
	int size=(hi-lo)>DEFAULT_MAXSIZE?(hi-lo):DEFAULT_MAXSIZE;
	List temp=list_create(size);
	temp->lastIndex=(hi-lo)-1;
	for(int i=0;i<(hi-lo);i++)
		temp->data[i]=arr[lo+i];
	return temp;
}


// 插入元素，位置不合法或者list不存在返回false（0<=index<=lastindex+1）
bool list_insert(List list,ElementType elem,int index) {
	if(list_exist(list)&&(index>=0&&index<=list->lastIndex+1)) {
		for(int i=list->lastIndex+1;i>index;i--)
			list->data[i]=list->data[i-1];
		list->data[index]=elem;
		list->lastIndex++;
		return true;
	}
	return false;
}

// 删除给定位置的元素，位置不合法或者list不存在返回false（0<=index<=lastindex）
bool list_delete(List list,int index) {
	if(list_exist(list)&&(index>=0&&index<=list->lastIndex)) {
		for(int i=index;i<list->lastIndex;i++)
			list->data[i]=list->data[i+1];
		list->lastIndex--;
		return true;
	}
	return false;
}

// 遍历线性表元素，对每个元素进行fun函数操作
void list_traverse(List list,void (*fun)(ElementType* eptr)) {
	if(list_exist(list)) {
		for(int i=0;i<=list->lastIndex;i++)
			fun(list->data+i);
	}
}

// 销毁线性表
void list_clear(List list) {
	if(list) {
		if(list->data)
			free(list->data);
		free(list);
	}
}