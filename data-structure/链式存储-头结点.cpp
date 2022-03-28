#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int Status;

typedef struct Node {
	Status value;
	Node* next;
}Node,*LinkList;

/* ��ʼ������ */
bool InitList(LinkList& L) {
	L= (Node*)malloc(sizeof(Node));
	if (L == NULL)
		return false;
	L->next = NULL;
	L->value = NULL;
	return true;
}
/*    �п�    */
bool Empty(LinkList L){
	return (L->next == NULL);
}
/*    ���    */
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
/* ����-β��  */
bool InitTailList(LinkList& L) {
	/* ��ȡ���һ���ڵ� ��֧�ַǳ�ʼ���������β��*/
	Node* LastNode = L;
	while (LastNode->next != NULL)
	{
		LastNode = LastNode->next;
	}

	Status Input;
	Node* InputLastNode;	//�洢���صĵ�ǰ�������һ���ڵ�
	scanf("%d", &Input);
	InputLastNode = LastNode;
	while (Input != 9999)
	{
		InputLastNode = InsertNextNode(InputLastNode, Input);		//������������
		scanf("%d", &Input);
	}
	return true;
}
/*    ͷ��    */
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
	return head;					//ͷ�巨����ڵ�ʱʹ��
}
/* ����-ͷ��  */
bool InitHeadList(LinkList& L) {
	/* �˺���ֻ�����ڿ�������� */
	Status Input;
	scanf("%d", &Input);
	while (Input != 9999)
	{
		Node* e = (Node*)malloc(sizeof(Node));
		e->next = L->next;
		L->next = e;
		e->value = Input;		//ע��˴�����Ҫ��ͷ��㻻ֵ
		scanf("%d", &Input);
	}
	return true;
}
/*  ��ӡ�ڵ�  */
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