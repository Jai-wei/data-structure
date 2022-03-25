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

bool Empty(LinkList L) {
	return (L->next == NULL);
}

bool InitList(LinkList& L) {
	L = (Node*)malloc(sizeof(Node));
	if (L == NULL)
		return false;						//内存分配失败
	L->next = NULL;							//归空
	return true;
}
bool ListInsert(LinkList& L, int i, Status e) {	//复杂度On
	if (i < 1)
		return false;
	Node* p;	int j = 0;		p = L;		// p先指向头结点，表示当前节点；j是第几个节点
	while (p != NULL && j<i-1) {				// 找到i-1，如插入2，改1
		p = p->next;
		j++;
	}
	if (p == NULL)							// i值不合法
		return false;
	Node *s = (Node*)malloc(sizeof(Node));
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






