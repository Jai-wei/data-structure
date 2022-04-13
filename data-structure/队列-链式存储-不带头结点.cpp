#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
	int data;
	LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

//初始化队列（带头结点）
void InitQueue(LinkQueue& Q) {
	Q.front = NULL;
	Q.rear = NULL;
}

//初始化一个队列
void testLinkQueue() {
	LinkQueue Q;
	InitQueue(Q);
}

//判空
bool Empty(LinkQueue Q){
	return (Q.front == NULL);
}

//入队
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

//出队
bool DeQueue(LinkQueue& Q, int& x) {
	if (Q.front == NULL)
		return false;
	LinkNode* p = Q.front;
	x = p->data;
	Q.front = p->next;			//如果是最后一个元素了，是Q.front直接指向空
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