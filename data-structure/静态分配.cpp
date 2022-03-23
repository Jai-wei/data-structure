#include <stdio.h>
#define MaxSize 10

typedef struct {
	int data[MaxSize];			//列表不需要使用内存分配函数
	int length;					//表示循序表的长度
}SqList;

void InitList(SqList &L) {		//需要更改L变量，使用 &
	for (int i = 0; i < MaxSize; i++)
		L.data[i] = 0;			//正常不应该访问大于length的数据元素，因此不必设置为0
	L.length = 0;				//顺序表长度为0，但数组内存长度为10
}

int main() {
	SqList L;
	InitList(L);
	return 0;
}







