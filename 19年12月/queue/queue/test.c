#include"queue.h"
// ��ʼ������
void QueueInit(Queue* q) {
	q->_back = NULL;
	q->_front = NULL;
}
// ��β�����
void QueuePush(Queue* q, QDataType data) {
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->_data = data;
	newnode->_pNext = NULL;
	if (q->_front == NULL) {
		q->_front = newnode;
		q->_back = newnode;
	}
	else {
		q->_back->_pNext = newnode;
		q->_back = newnode;
	}

}
// ��ͷ������
void QueuePop(Queue* q) {
	assert(q);
	if (q->_front == NULL)
		return;
	QNode* next = q->_front->_pNext;
	if (q->_front == q->_back) {
		q->_back = next;
	}
	free(q->_front);
	q->_front = next;
}
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q) {
	assert(q);
	return q->_front->_data;
}
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q) {
	assert(q);
	return q->_back->_data;
}
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q) {
	assert(q);
	QNode* next = q->_front;
	QDataType sum = 0;
	while (next != NULL) {
		next = next->_pNext;
		sum++;
	}
	return sum;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q) {
	assert(q);
	return q->_front == NULL;
}
// ���ٶ���
void QueueDestroy(Queue* q) {
	assert(q);
	if (q->_front == NULL)
		return;
	QNode* next = q->_front->_pNext;
	while (next)
	{
		free(q->_front);
		q->_front = next;
		next = next->_pNext;
	}
	free(q->_front);
	q->_front = NULL;
	q->_back = NULL;
}
int main() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	QueueInit(q);
	int x = QueueEmpty(q);
	printf("%d", x);
	QueuePush(q, 1);
	QueuePush(q, 2);
	QueuePush(q, 3);
	QueuePush(q, 4);
	QueuePush(q, 5);
	x = QueueEmpty(q);
	printf("%d", x);
	x = QueueFront(q);
	printf("%d", x);
	QueuePop(q);
	x = QueueFront(q);
	printf("%d", x);
	x = QueueSize(q);
	printf("%d", x);
	QueueDestroy(q);
	x = QueueSize(q);
	printf("%d", x);
	return 0;
}