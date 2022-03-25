#include <stdio.h>
#include <stdlib.h>
typedef int Status;


typedef struct Node {
	Status data;
	Node* next;
}Node, * LinkList;

bool InitList(LinkList& L) {	
	L = NULL;
	return true;
}
bool Empty(LinkList L) {		
	return (L == NULL);
}

bool ListInsert(LinkList& L, int i, Status e) {
	if (i < 1)
		return false;
	if (i == 1){										// 当在第一个位置插入时
		Node* s = (Node*)malloc(sizeof(Node));
		s->data = e;
		s->next = L;									// ！！L的起始地址就是S，不用L.next
		L = s;											// ！！头指针指向第一个节点
		return true;
	}

	int j = 1;											// 注意是1开始，指向第几个节点
	Node* p;											// 建立转存变量，和s区分开
	p = L;
	while (p != NULL && j < i-1){
		p = p->next;
		j++;
	}
	if (p == NULL)										// i大于当前链表长度
		return false;

	Node* s = (Node*)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}


void test() {
	LinkList L;
	InitList(L);
}


int main() {

	test();
	return 0;
}






