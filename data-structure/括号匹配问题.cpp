//����ƥ�䣬ÿ��ƥ����������ţ���LIFO
//ע��ƥ���ʱ��ջ�յ����
//ƥ�����ջ�ڳ��ֲ��������

#include <stdio.h>
#define MaxSize 10
typedef struct {
	char data[MaxSize];
	int top;		//ջ��ָ��(������±�)
}SqStack;

//��ʼ��ջ
void InitStack(SqStack &S) {
	S.top = -1;
}

//�п�
bool StackEmpty(SqStack S) {
	return (S.top == -1);
}

//��ջ
bool Push(SqStack& S, char x) {
	if (S.top == MaxSize - 1)
		return false;
	S.data[++S.top] = x;
	return true;
}

//��ջ
bool Pop(SqStack& S,char& x){
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}

//����ƥ��
bool brackertCheck(char str[], int length) {		//length<10
	SqStack S;
	InitStack(S);
	for (int i = 0; i < length; i++) {
		if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
			Push(S, str[i]);
		}
		else {
			if(StackEmpty(S))
				return false;

			char p;
			Pop(S, p);
			if (str[i] == '(' && p != ')')
				return false;
			if (str[i] == '{' && p != '}')
				return false;
			if (str[i] == '[' && p != ']')
				return false;
		}	
	}
	return StackEmpty(S);			// !!! �����Ҫ�ж��Ƿ�ջ��!!!
}

int main() {
	return 0;
}