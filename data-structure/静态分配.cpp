#include <stdio.h>
#define MaxSize 10

typedef struct {
	int data[MaxSize];			//�б���Ҫʹ���ڴ���亯��
	int length;					//��ʾѭ���ĳ���
}SqList;

void InitList(SqList &L) {		//��Ҫ����L������ʹ�� &
	for (int i = 0; i < MaxSize; i++)
		L.data[i] = 0;			//������Ӧ�÷��ʴ���length������Ԫ�أ���˲�������Ϊ0
	L.length = 0;				//˳�����Ϊ0���������ڴ泤��Ϊ10
}

int main() {
	SqList L;
	InitList(L);
	return 0;
}







