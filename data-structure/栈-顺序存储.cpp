#include <stdio.h>

#define MaxSize 10
typedef struct {
	int data[10];
	int top;		//栈顶指针(数组的下标)
}SqStack;

//初始化栈
void InitStack(SqStack &S) {
	S.top = -1;
}
//创建并初始化一个栈
void testStack() {
	SqStack S;
	InitStack(S);
}
//判空
bool StackEmpty(SqStack S) {
	return (S.top == -1);
}
//进栈
bool Push(SqStack& S, int x) {
	if (S.top == MaxSize - 1)
		return false;
	S.data[++S.top] = x;	// -1 +1 = 0
	return true;
}
//出栈
bool Pop(SqStack& S,int& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}
//读栈顶元素
bool GetTop(SqStack S, int& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

//共享栈：从两边增长，判满：top0 + 1 == top1


 
int main() {
	testStack();

	return 0;
}
