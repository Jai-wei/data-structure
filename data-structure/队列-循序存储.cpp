#include <stdio.h>

#define MaxSize 10
typedef struct {
	int data[MaxSize];
	int front, rear;
}SqQueue;

//��ʼ��
void InitQueue(SqQueue& Q) {
	Q.rear = Q.front = 0;		//��βָ��ָ����һ���ò���Ԫ�ص�λ��
}
//��������ʼ��
void testQueue() {
	SqQueue Q;
	InitQueue(Q);
}
//�п�
bool QueueEmpty(SqQueue Q) {
	return (Q.front == Q.rear);
}
//���
bool InQueue(SqQueue& Q, int x) {
	if ((Q.rear + 1) % MaxSize == Q.front)	//����һ���洢��Ԫ��β+1 = ͷ����ʾ����
											//��������������Ǿ�Ҫ�ڽṹ���ﶨ��һ��size����¼���г���
											//���߽ṹ�嶨��һ��tag��¼ɾ��/���������ɾ�����¿գ����뵼������0/1)
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;		//ȡģ�����ͷָ��ȡ����Ԫ�أ�βָ��������ָ��0
	return true;
}
//����
bool DeQueue(SqQueue& Q, int& x) {
	if (Q.front == Q.rear)
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;		//ע������Ҳ��+1
	return true;
}
//��ȡͷԪ�ص�ֵ
bool GetHead(SqQueue Q, int& x) {
	if (Q.front == Q.rear)
		return false;
	x = Q.data[Q.front];
	return true;
}
//����
int LengthQueue(SqQueue Q) {
	return ((Q.rear + MaxSize - Q.front) % MaxSize);
}


int main() {
	testQueue();

	return 0;
}