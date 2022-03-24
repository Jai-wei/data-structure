#include <stdio.h>

#define MaxSize 10
#define Error 0
#define TRUE 1
#define FALSE 0
#define OK 1

typedef int Status;



typedef struct {
	Status data[MaxSize];			//�б���Ҫʹ���ڴ���亯��
	int length;						//��ʾѭ���ĳ���
}SqList;

void InitList(SqList &L) {			//��Ҫ����L������ʹ�� &
	for (int i = 0; i < MaxSize; i++)
		L.data[i] = 0;				//������Ӧ�÷��ʴ���length������Ԫ�أ���˲�������Ϊ0
	L.length = 9;					//˳�����Ϊ0���������ڴ泤��Ϊ10
}

Status GetElem(SqList L, int i, Status &e) {
	if (L.length == 0 || L.length < i || i <1)		//ע����i<1�����
		return Error;
	e = L.data[i];
	return OK;
}

Status ListInsert(SqList& L, int i, Status e) {		//�ڵ�i�����루��ʵi��
	if (L.length == MaxSize || (i < 1 || i > L.length + 1))
		return Error;
	if (i <= L.length) {
		for (int k = L.length; k >= i; k--)
			L.data[k] = L.data[k - 1];				//û��data[10],���ǲ��ᱨ��
	}
	L.data[i - 1] = e;
	L.length++;
	return OK;
}




int main() {
	SqList L;
	InitList(L);
	ListInsert(L, 2, 3);
	return 0;
}







