#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
	int data;
	LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

//��ʼ�����У���ͷ��㣩
void InitQueue(LinkQueue& Q) {
	Q.front = NULL;
	Q.rear = NULL;
}

//��ʼ��һ������
void testLinkQueue() {
	LinkQueue Q;
	InitQueue(Q);
}

//�п�
bool Empty(LinkQueue Q){
	return (Q.front == NULL);
}

//���
void Enqueue(LinkQueue& Q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q.front->next == NULL) {
		Q.front = s;
		Q.rear = s;
	}
	else
	{
		Q.rear->next = s;
		Q.rear = s;
	}
}

//����
bool DeQueue(LinkQueue& Q, int& x) {
	if (Q.front == NULL)
		return false;
	LinkNode* p = Q.front;
	x = p->data;
	Q.front = p->next;			//��������һ��Ԫ���ˣ���Q.frontֱ��ָ���
	if (Q.rear == p) {
		Q.front = NULL;
		Q.rear = NULL;
	}
	free(p);
	return true;
}


int main() {
	testLinkQueue;
	return 0;
}