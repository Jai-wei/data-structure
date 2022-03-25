#include <stdio.h>
#include <stdlib.h>
typedef int Status;


typedef struct Node{
	Status data;
	Node* next;
}Node, *LinkList;

//bool Initlist(LinkList& L) {	//����ͷ���
//	L = NULL;
//	return true;
//}
//bool Empty(LinkList L) {		//����ͷ���
//	return (L == NULL);
//}

bool Empty(LinkList L) {
	return (L->next == NULL);
}

bool InitList(LinkList& L) {
	L = (Node*)malloc(sizeof(Node));
	if (L == NULL)
		return false;						//�ڴ����ʧ��
	L->next = NULL;							//���
	return true;
}
bool ListInsert(LinkList& L, int i, Status e) {	//���Ӷ�On
	if (i < 1)
		return false;
	Node* p;	int j = 0;		p = L;		// p��ָ��ͷ��㣬��ʾ��ǰ�ڵ㣻j�ǵڼ����ڵ�
	while (p != NULL && j<i-1) {				// �ҵ�i-1�������2����1
		p = p->next;
		j++;
	}
	if (p == NULL)							// iֵ���Ϸ�
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






