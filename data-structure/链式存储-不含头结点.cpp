#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef struct Node {
	Status value;
	Node* next;
}Node,* Linklist;

/*   初始化   */
bool InitList(Linklist& L) {
	L = NULL;
	return true;
}
/*    判空    */
bool Empty(Linklist L) {
	if (L == NULL)
		return true;
	return false;
}
/*    后插    */
Node* InsertNextNode(Node* old, Status value) {
	if (old == NULL)
		return NULL;
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
		return NULL;
	p->value = value;
	p->next = old->next;
	old->next = p;
	return p;
}
/*  创建-尾插 */
bool InitTailList(Linklist& L) {
	Status value;
	scanf("%d", &value);
	Node* s = L;
	if (L == NULL) {
		Node* p = (Node*)malloc(sizeof(Node));
		if (p == NULL)
			return false;
		p->value = value;
		p->next = NULL;
		L = p;
		s = p;
	}
	if(L != NULL) {
		scanf("%d", &value);
		while (value != 9999)
		{	
			
			s = InsertNextNode(s, value);
			scanf("%d", &value);
		}
	}
	return true;
}
/*    打印    */
bool PrintList(Linklist L) {
	if (L == NULL)
		return false;
	Node* p = L;
	while (p != NULL)
	{
		printf("%d\t", p->value);
		p = p->next;
	}
	printf("\n");
	return true;
}
/*    头插    */
Node* InsertHeadNode(Node* old, Status value) {
	if (old == NULL)
		return NULL;
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
		return NULL;
	p->value = old->value;
	old->value = value;
	p->next = old->next;
	old->next = p;
	return p;
}
/*  创建-头插 */
bool InitHeadList(Linklist& L) {
	//该函数只能用于初始化，不适合在已创建列表后再连续用头插插入节点
	Status value;
	Node* s = L;
	scanf("%d", &value);
	if (value == 9999)
		return false;
	if (L == NULL) {
		Node* p = (Node*)malloc(sizeof(Node));
		p->value = value;
		p->next = NULL;
		L = p;
		s = p;
	}
	if (L != NULL) {
		scanf("%d", &value);
		while (value != 9999)
		{
			InsertHeadNode(s, value);
			scanf("%d", &value);
		}
	}
	return true;
}
/*  按值查找  */
Node* FindNodeValue(Linklist L, Status value) {
	if (L == NULL)
		return NULL;
	Node* p = L;
	while (p != NULL && p->value != value)
	{
		p = p->next;
	}
	return p;
}
/*  按位查找  */
Node* FindNodeNum(Linklist L, int i) {
	if (L == NULL || i <1)
		return NULL;
	Node* p = L;	int num = 1;
	while (p != NULL && num < i)
	{
		p = p->next;
		num++;
	}
	return p;
}
/*  删除节点  */
bool DeleteNode(Node* old) {
	if (old == NULL || old->next == NULL)
		return false;
	//Status bet;
	//bet = old->value;
	old->value = old->next->value;
	//old->next->value = bet;
	old->next = old->next->next;
	//free(old->next->next);
	return true;
}
/*  按位插入  */
bool InsertNumNode(Linklist L, int i, Status value) {
	if (L == NULL || i < 1)
		return false;
	Node* p = L;	int num = 1;
	while (p != NULL && num < i)
	{
		p = p->next;
		num++;
	}
	InsertHeadNode(p, value);
	return true;
}
/*  按位删除  */
bool DeleteNode(Linklist L, int i,Status &value) {
	if (L == NULL || i < 1)
		return false;
	Node* e = FindNodeNum(L, i);
	DeleteNode(e);
	return true;
}
/*    长度    */
int ListLength(Linklist L) {
	int length = 0;
	Node* p = L;
	while (p != NULL)
	{
		p = p->next;
		length++;
	}
	return length;
}


int main() {
	Linklist Test;
	InitList(Test);
	InitHeadList(Test);
	PrintList(Test);
	int x;
	x = ListLength(Test);
	printf("%d", x);
	return 0;
}