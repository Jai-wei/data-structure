#include <stdio.h>

#define MaxSize 10
typedef struct {
	int data[MaxSize];
	int front, rear;
}SqQueue;

//初始化
void InitQueue(SqQueue& Q) {
	Q.rear = Q.front = 0;		//队尾指针指向下一个该插入元素的位置
}
//创建并初始化
void testQueue() {
	SqQueue Q;
	InitQueue(Q);
}
//判空
bool QueueEmpty(SqQueue Q) {
	return (Q.front == Q.rear);
}
//入队
bool InQueue(SqQueue& Q, int x) {
	if ((Q.rear + 1) % MaxSize == Q.front)	//牺牲一个存储单元，尾+1 = 头，表示满了
											//如果不想牺牲，那就要在结构体里定义一个size，记录队列长度
											//或者结构体定义一个tag记录删除/插入操作，删除导致空，插入导致满（0/1)
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;		//取模，如果头指针取出了元素，尾指针再重新指向0
	return true;
}
//出队
bool DeQueue(SqQueue& Q, int& x) {
	if (Q.front == Q.rear)
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;		//注意这里也是+1
	return true;
}
//获取头元素的值
bool GetHead(SqQueue Q, int& x) {
	if (Q.front == Q.rear)
		return false;
	x = Q.data[Q.front];
	return true;
}
//长度
int LengthQueue(SqQueue Q) {
	return ((Q.rear + MaxSize - Q.front) % MaxSize);
}


int main() {
	testQueue();

	return 0;
}