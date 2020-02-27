// test.c

#include "list.h"

void printELem(ElementType* eptr) {
	printf("%d ",*eptr);
}

void printList(List list) {
	printf("list has %d members:\n",list->lastIndex+1);
	list_traverse(list,printELem);
	putchar('\n');
}

int main(void) {
	int arr[]={0,1,2,3,4,5,6,7,8,9};
	List myList=list_copyfrom(arr,3,9);
	printList(myList);
	putchar('\n');

	puts("insert 999 to index 1");
	list_insert(myList,999,1);
	printList(myList);
	putchar('\n');

	puts("delete index 0");
	list_delete(myList,0);
	printList(myList);

	list_clear(myList);
	return EXIT_SUCCESS;
}