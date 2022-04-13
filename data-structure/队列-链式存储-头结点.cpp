#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
	int data;
	LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

//初始化队列
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
	Q.front->data = NULL;
}

//初始化一个队列
void testLinkQueue() {
	LinkQueue Q;
	InitQueue(Q);
}

//判空
bool Empty(LinkQueue Q) {
	return (Q.front->next == Q.rear->next);
}

//入队
void InQueue(LinkQueue& Q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;		//将rear当前指向的节点的尾指针指向新节点（连起来）
	Q.rear = s;				//将rear指向新节点（尾指针)
							//注意rear里有next和data。rear要等于s，且rear的next要指向s
}

//出队
bool DeQueue(LinkQueue& Q, int& x) {
	if (Q.front == Q.rear)
		return false;
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;		//如果是最后一个元素了，确实需要先执行这一步，是front.next指向空，而不是front指向空
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return true;
}






int main() {
	testLinkQueue;
	return 0;
}

