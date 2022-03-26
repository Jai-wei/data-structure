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
	if (i == 1){										// ���ڵ�һ��λ�ò���ʱ
		Node* s = (Node*)malloc(sizeof(Node));
		s->data = e;
		s->next = L;									// ����L����ʼ��ַ����S������L.next
		L = s;											// ����ͷָ��ָ���һ���ڵ�
		return true;
	}

	int j = 1;											// ע����1��ʼ��ָ��ڼ����ڵ�
	Node* p;											// ����ת���������s���ֿ�
	p = L;
	while (p != NULL && j < i-1){
		p = p->next;
		j++;
	}
	if (p == NULL)										// i���ڵ�ǰ������
		return false;

	Node* s = (Node*)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
bool InsertNextNode(Node* p, Status e) {		//����������p�ڵ�֮�����Ԫ��e
	if (p == NULL)
		return false;
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
bool InsertPriorNode(Node* p, Status e) {		//ǰ���������p֮ǰ����e��ͨ��˳����ʵ�֣�
	if (p == NULL)
		return false;
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL)
		return false;
	s->data = p->data;
	s->next = p->next;
	p->data = e;
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






