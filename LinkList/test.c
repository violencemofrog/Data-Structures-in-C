// test.c

#include "linklist.h"

void printElem(ElementType* eptr) {
	printf("%d ",*eptr);
}

void printList(LinkList listhead) {
	printf("All members:");
	linklist_traverse(listhead,printElem);
	putchar('\n');
}

int main(void) {
	int arr[]={0,1,2,3,4,5,6,7,8,9,10};
	LinkList myLinkList=linklist_copyfrom(arr,1,9);
	printList(myLinkList);

	puts("\ninsert 999 to 2");
	linklist_insert(myLinkList,999,2);
	printList(myLinkList);

	puts("\ndelete first member");
	linklist_delete(myLinkList,1);
	printList(myLinkList);
	
	puts("\ndelete last member");
	linklist_delete(myLinkList,8);
	printList(myLinkList);

	linklist_clear(myLinkList);
	return EXIT_SUCCESS;
}