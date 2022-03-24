#include <stdio.h>
#include <stdlib.h>
typedef int Status;


typedef struct Node{
	Status data;
	Node* next;
}Node, *LinkList;

//bool Initlist(LinkList& L) {	//不带头结点
//	L = NULL;
//	return true;
//}
//bool Empty(LinkList L) {		//不带头结点
//	return (L == NULL);
//}



bool InitList(LinkList& L) {
	L = (Node*)malloc(sizeof(Node));
	if (L == NULL)
		return false;
	L->next = NULL;
	return true;
}
bool Empty(LinkList L) {
	return (L->next == NULL);
}



void test() {
	LinkList L;
	InitList(L);
}


int main() {

	test();
	return 0;
}






