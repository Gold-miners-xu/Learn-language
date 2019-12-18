#include<stdio.h>
#include<assert.h>
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
