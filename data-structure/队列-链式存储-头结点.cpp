#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
	int data;
	LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

//��ʼ������
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
	Q.front->data = NULL;
}

//��ʼ��һ������
void testLinkQueue() {
	LinkQueue Q;
	InitQueue(Q);
}

//�п�
bool Empty(LinkQueue Q) {
	return (Q.front->next == Q.rear->next);
}

//���
void InQueue(LinkQueue& Q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;		//��rear��ǰָ��Ľڵ��βָ��ָ���½ڵ㣨��������
	Q.rear = s;				//��rearָ���½ڵ㣨βָ��)
							//ע��rear����next��data��rearҪ����s����rear��nextҪָ��s
}

//����
bool DeQueue(LinkQueue& Q, int& x) {
	if (Q.front == Q.rear)
		return false;
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;		//��������һ��Ԫ���ˣ�ȷʵ��Ҫ��ִ����һ������front.nextָ��գ�������frontָ���
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return true;
}






int main() {
	testLinkQueue;
	return 0;
}

