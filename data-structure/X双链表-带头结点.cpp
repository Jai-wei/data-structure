#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef struct DNode {
	Status value;
	struct DNode* prior, * next;
}DNode, *DLinklist;

//初始化双链表
bool InitDLinkList(DLinklist& L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior = NULL;
	L->next = NULL;
	L->value = NULL;
}
//判空
bool Empty(DLinklist L) {
	return(L->next == NULL);
}
//在p节点之后插入s节点(后插）
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
//删除p节点后的q节点
bool DeleteDNode(DNode* p) {
	if (p == NULL)
		return false;
	DNode* q = p->next;
	if (q == NULL)
		return false;		//无后继
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = p;
	free(q);
	return true;
}
//销毁双链表
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







