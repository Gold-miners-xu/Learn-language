#include<stdio.h>
#include<assert.h>
typedef int QDataType;
// ��ʽ�ṹ����ʾ����
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;
// ���еĽṹ
typedef struct Queue
{
	QNode* _front;
	QNode* _back;
}Queue;
