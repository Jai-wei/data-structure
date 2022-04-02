#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef struct DNode {
	Status value;
	struct DNode* prior, * next;
}DNode, *DLinklist;

//��ʼ��˫����
bool InitDLinkList(DLinklist& L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior = NULL;
	L->next = NULL;
	L->value = NULL;
}
//�п�
bool Empty(DLinklist L) {
	return(L->next == NULL);
}
//��p�ڵ�֮�����s�ڵ�(��壩
bool InsertNextDNode(DNode* p, DNode* s) {
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	p->next = s;
	if(p->next != NULL)
		p->next->prior = s;
	s->prior = p;
	return true;
}
//ɾ��p�ڵ���q�ڵ�
bool DeleteDNode(DNode* p) {
	if (p == NULL)
		return false;
	DNode* q = p->next;
	if (q == NULL)
		return false;		//�޺��
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = p;
	free(q);
	return true;
}
//����˫����
void DestoryList(DLinklist& L) {
	while (L->next != NULL)
	{
		DeleteDNode(L);
	}
	free(L);
	L = NULL;
}

int main() {
	
	return 0;
}







