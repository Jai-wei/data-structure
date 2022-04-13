#include <stdio.h>

#define MaxSize 10
typedef struct {
	int data[10];
	int top;		//ջ��ָ��(������±�)
}SqStack;

//��ʼ��ջ
void InitStack(SqStack &S) {
	S.top = -1;
}
//��������ʼ��һ��ջ
void testStack() {
	SqStack S;
	InitStack(S);
}
//�п�
bool StackEmpty(SqStack S) {
	return (S.top == -1);
}
//��ջ
bool Push(SqStack& S, int x) {
	if (S.top == MaxSize - 1)
		return false;
	S.data[++S.top] = x;	// -1 +1 = 0
	return true;
}
//��ջ
bool Pop(SqStack& S,int& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}
//��ջ��Ԫ��
bool GetTop(SqStack S, int& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

//����ջ��������������������top0 + 1 == top1


 
int main() {
	testStack();

	return 0;
}
