#include<stdio.h>
#include<assert.h>
#include<string.h>
typedef int QDataType;
// 链式结构：表示队列
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;
// 队列的结构
typedef struct Queue
{
	QNode* _front;
	QNode* _back;
}Queue;
typedef struct {
	Queue* q1;
	Queue* q2;
} MyStack;
void QueueInit(Queue* q) {
	//Queue* q = (Queue*)malloc(sizeof(Queue));
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
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q) {
	assert(q);
	return q->_front == NULL;
}


/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack) * sizeof(Queue));
	QueueInit(obj->q1);
	QueueInit(obj->q2);
	return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (obj->q1->_front == NULL && obj->q2->_front == NULL)
		QueuePush(obj->q1, x);
	else if (obj->q1->_front == NULL)
		QueuePush(obj->q2, x);
	else
		QueuePush(obj->q1, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int x = 0;
	if (obj->q1->_front == NULL) {
		for (int i = QueueSize(obj->q2); i > 1; i--) {
			QueuePush(obj->q1, QueueFront(obj->q2));
			QueuePop(obj->q2);
		}
		x = QueueFront(obj->q2);
		QueuePop(obj->q2);
		return x;
	}
	else {
		for (int i = QueueSize(obj->q1); i > 1; i--) {
			QueuePush(obj->q2, QueueFront(obj->q1));
			QueuePop(obj->q1);
		}
		x = QueueFront(obj->q1);
		QueuePop(obj->q1);
		return x;
	}
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (obj->q1->_front == NULL && obj->q2->_front == NULL)
		return QueueBack(obj->q1);
	else if (obj->q1->_front == NULL)
		return QueueBack(obj->q2);
	else
		return QueueBack(obj->q1);
}

/** Returns whether the stack is empty. */
//bool myStackEmpty(MyStack* obj) {
//	return QueueEmpty(obj->q1) && QueueEmpty(obj->q2);
//}

void myStackFree(MyStack* obj) {
	QueueDestroy(obj->q1);
	QueueDestroy(obj->q2);
}
