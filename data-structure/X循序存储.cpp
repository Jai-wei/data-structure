#include <stdio.h>

#define MaxSize 10
#define Error 0
#define TRUE 1
#define FALSE 0
#define OK 1

typedef int Status;



typedef struct {
	Status data[MaxSize];			//列表不需要使用内存分配函数
	int length;						//表示循序表的长度
}SqList;

void InitList(SqList &L) {			//需要更改L变量，使用 &
	for (int i = 0; i < MaxSize; i++)
		L.data[i] = 0;				//正常不应该访问大于length的数据元素，因此不必设置为0
	L.length = 9;					//顺序表长度为0，但数组内存长度为10
}

Status GetElem(SqList L, int i, Status &e) {
	if (L.length == 0 || L.length < i || i <1)		//注意有i<1的情况
		return Error;
	e = L.data[i];
	return OK;
}

Status ListInsert(SqList& L, int i, Status e) {		//在第i处插入（现实i）
	if (L.length == MaxSize || (i < 1 || i > L.length + 1))
		return Error;
	if (i <= L.length) {
		for (int k = L.length; k >= i; k--)
			L.data[k] = L.data[k - 1];				//没有data[10],但是不会报错
	}
	L.data[i - 1] = e;								//最后一个，不进循环
	L.length++;
	return OK;
}

Status ListDelete(SqList& L, int i, Status &e) {
	if (L.length == 0 || (i<1 || i>L.length))
		return Error;

	e = L.data[i-1];

	if (i < L.length) {
		for (int k = i; k < L.length; k++)		//不用等于length，最后一个数组不管
			L.data[k - 1] = L.data[k];
	}
	L.length--;									//如果是最后一个，直接减减，不进循环
	return e;
}








//int main() {
//	SqList L;
//	InitList(L);
//	ListInsert (L, 10, 3);
//	return 0;
//}







