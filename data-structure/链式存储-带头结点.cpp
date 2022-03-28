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
		return false;						//内存分配失败
	L->next = NULL;							//归空
	return true;
}
bool ListInsert(LinkList& L, int i, Status e) {	//复杂度On
	if (i < 1)
		return false;
	Node* p;	int j = 0;		p = L;		// p先指向头结点，表示当前节点；j是第几个节点
	while (p != NULL && j<i-1) {				// 找到i-1，如插入2，改1
		p = p->next;
		j++;
	}
	if (p == NULL)							// i值不合法
		return false;
	Node *s = (Node*)malloc(sizeof(Node));
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
bool ListDelete(LinkList& L, int i, Status &e) {			//注意e是&，需要带入e
	if (i < 1)
		return false;
	int j = 0;	Node* s;
	s = L;
	if (s != NULL && j < i - 1) {
		s = s->next;
		j++;
	}
	if (s == NULL || s->next == NULL)		//注意判断s.next,为什么？？？？？
		return false;
	//e = s->data;
	//s->next = s->next->next;
	Node* p = s->next;						//？？？？？ 是否创建了第二个地址，还是直接复制过去的？
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}
bool DeleteNode(Node* p) {		//删除指定节点
	if (p == NULL)				//不需要|| p->next == NULL？？？？？
		return false;
	Node* s = p->next;
	if (s->next == NULL)
		return false;			//如果是最后一个节点，只能从头遍历删除
	p->data = s->data;			
	p->next = s->next;
	free(s);
	return true;

}
Node* GetNode(LinkList L, int i) {		//按位查找
	if (i < 0)
		return NULL;
	int j = 0;	 Node* p;
	p = L;
	while (p!=NULL && j<i)			// i=0时直接返回p,即头结点。当i大于链表长度时，p = null，返回null
	{
		p = p->next;
		j++;
	}
	return p;
}
Node* LocateNode(LinkList L, Status e) {	//按值查找,找不到就返回null
	Node* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}
int Length(LinkList L) {
	int len = 0;
	Node* s = L->next;			//直接等于L？？？？？
	while (s != NULL)
	{
		s = s->next;
		len++;
	}
	return len;
}
bool InsertNextNode(Node* p, Status e) {		//后插操作：在p节点之后插入元素e
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
bool InsertPriorNode(Node* p, Status e) {		//前插操作，在p之前插入e。通过顺移来实现！
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
LinkList List_TailInsert(LinkList& L) {		//尾插法
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
LinkList List_HeadInsert(LinkList& L) {			//头插法，逆置
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






