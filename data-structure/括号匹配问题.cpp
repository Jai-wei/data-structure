//括号匹配，每次匹配最近的括号，即LIFO
//注意匹配的时候，栈空的情况
//匹配完后，栈内出现残留的情况

#include <stdio.h>
#define MaxSize 10
typedef struct {
	char data[MaxSize];
	int top;		//栈顶指针(数组的下标)
}SqStack;

//初始化栈
void InitStack(SqStack &S) {
	S.top = -1;
}

//判空
bool StackEmpty(SqStack S) {
	return (S.top == -1);
}

//入栈
bool Push(SqStack& S, char x) {
	if (S.top == MaxSize - 1)
		return false;
	S.data[++S.top] = x;
	return true;
}

//出栈
bool Pop(SqStack& S,char& x){
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}

//括号匹配
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
	return StackEmpty(S);			// !!! 最后需要判定是否栈空!!!
}

int main() {
	return 0;
}