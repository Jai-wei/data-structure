#include <stdio.h>
#include <stdlib.h>
typedef int Status;


typedef struct Node{
	Status data;
	Node* next;
}Node, *LinkList;

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
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
bool ListDelete(LinkList& L, int i, Status &e) {			//ע��e��&����Ҫ����e
	if (i < 1)
		return false;
	int j = 0;	Node* s;
	s = L;
	if (s != NULL && j < i - 1) {
		s = s->next;
		j++;
	}
	if (s == NULL || s->next == NULL)		//ע���ж�s.next,Ϊʲô����������
		return false;
	//e = s->data;
	//s->next = s->next->next;
	Node* p = s->next;						//���������� �Ƿ񴴽��˵ڶ�����ַ������ֱ�Ӹ��ƹ�ȥ�ģ�
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}
bool DeleteNode(Node* p) {		//ɾ��ָ���ڵ�
	if (p == NULL)				//����Ҫ|| p->next == NULL����������
		return false;
	Node* s = p->next;
	if (s->next == NULL)
		return false;			//��������һ���ڵ㣬ֻ�ܴ�ͷ����ɾ��
	p->data = s->data;			
	p->next = s->next;
	free(s);
	return true;

}
Node* GetNode(LinkList L, int i) {		//��λ����
	if (i < 0)
		return NULL;
	int j = 0;	 Node* p;
	p = L;
	while (p!=NULL && j<i)			// i=0ʱֱ�ӷ���p,��ͷ��㡣��i����������ʱ��p = null������null
	{
		p = p->next;
		j++;
	}
	return p;
}
Node* LocateNode(LinkList L, Status e) {	//��ֵ����,�Ҳ����ͷ���null
	Node* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}
int Length(LinkList L) {
	int len = 0;
	Node* s = L->next;			//ֱ�ӵ���L����������
	while (s != NULL)
	{
		s = s->next;
		len++;
	}
	return len;
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
LinkList List_TailInsert(LinkList& L) {		//β�巨
	InitList(L);
	Status x;
	scanf("%d", &x);
	Node* s, *p = L;
	while (x!=9999)
	{
		s = (Node*)malloc(sizeof(Node));
		s->data = x;
		p->next = s;
		p = s;
		scanf("%d", &x);
	}
	p->next = NULL;
	return L;
}
LinkList List_HeadInsert(LinkList& L) {			//ͷ�巨������
	InitList(L);
	Node* s;
	int x;
	scanf("%d", &x);
	while (x != 9999) {
		s = (Node*)malloc(sizeof(Node));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}


void test() {
	LinkList L;
	InitList(L);
}
int main() {

	test();
	return 0;
}






