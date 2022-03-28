#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int Status;

typedef struct Node {
	Status value;
	Node* next;
}Node,*LinkList;

/* 初始化链表 */
bool InitList(LinkList& L) {
	L= (Node*)malloc(sizeof(Node));
	if (L == NULL)
		return false;
	L->next = NULL;
	L->value = NULL;
	return true;
}
/*    判空    */
bool Empty(LinkList L){
	return (L->next == NULL);
}
/*    后插    */
Node* InsertNextNode(Node *old,Status value) {
	if (old == NULL)
		return 0;
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL)
		return 0;
	s->value = value;
	s->next = old->next;
	old->next = s;
	return s;
}
/* 创建-尾插  */
bool InitTailList(LinkList& L) {
	/* 获取最后一个节点 ，支持非初始链表的连续尾插*/
	Node* LastNode = L;
	while (LastNode->next != NULL)
	{
		LastNode = LastNode->next;
	}

	Status Input;
	Node* InputLastNode;	//存储返回的当前链表最后一个节点
	scanf("%d", &Input);
	InputLastNode = LastNode;
	while (Input != 9999)
	{
		InputLastNode = InsertNextNode(InputLastNode, Input);		//↑↑↑↑↑↑
		scanf("%d", &Input);
	}
	return true;
}
/*    头插    */
Node* InsertHeadNode(Node* head, Status value) {
	if (head == NULL)
		return 0;
	Node* e = (Node*)malloc(sizeof(Node));
	if (e == NULL)
		return 0;
	e->value = head->value;
	head->value = value;
	e->next = head->next;
	head->next = e;
	return head;					//头插法插入节点时使用
}
/* 创建-头插  */
bool InitHeadList(LinkList& L) {
	/* 此函数只适用于空链表插入 */
	Status Input;
	scanf("%d", &Input);
	while (Input != 9999)
	{
		Node* e = (Node*)malloc(sizeof(Node));
		e->next = L->next;
		L->next = e;
		e->value = Input;		//注意此处不需要与头结点换值
		scanf("%d", &Input);
	}
	return true;
}
/*  打印节点  */
bool PrintList(LinkList L) {
	if (L->next == NULL)
		return false;
	Node* e = L->next;
	while (e != NULL)
	{
		printf("%d\t", e->value);
		e = e->next;
	}
	return true;
}
/*  */


/*  */


/*  */


/*  */


/*  */






int main() {
	LinkList Test;
	InitList(Test);
	InitHeadList(Test);
	PrintList(Test);
	return 0;
}