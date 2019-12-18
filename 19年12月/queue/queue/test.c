#include"queue.h"
// 初始化队列
void QueueInit(Queue* q) {
	q->_back = NULL;
	q->_front = NULL;
}
// 队尾入队列
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
// 队头出队列
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
// 获取队列头部元素
QDataType QueueFront(Queue* q) {
	assert(q);
	return q->_front->_data;
}
// 获取队列队尾元素
QDataType QueueBack(Queue* q) {
	assert(q);
	return q->_back->_data;
}
// 获取队列中有效元素个数
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
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q) {
	assert(q);
	return q->_front == NULL;
}
// 销毁队列
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