#include<stdio.h>
#include<assert.h>
#include<string.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // ջ��
	int _capacity; // ����
}Stack;
// ��ʼ��ջ
void StackInit(Stack* ps) {
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}
// ��ջ
void StackPush(Stack* ps, STDataType data) {
	assert(ps);
	if (ps->_top == ps->_capacity) {
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// ��ջ
void StackPop(Stack* ps) {
	assert(ps && ps->_top > 0);
	--ps->_top;
}
// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps) {
	assert(ps);
	return ps->_a[ps->_top - 1];
}
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps) {
	assert(ps);
	return ps->_top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps) {
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}
// ����ջ
void StackDestroy(Stack* ps) {
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;

}
typedef struct {
	Stack* in;
	Stack* out;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	obj->in = (Stack*)malloc(sizeof(Stack));
	obj->out = (Stack*)malloc(sizeof(Stack));
	StackInit(obj->in);
	StackInit(obj->out);
	return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(obj->in, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int size = StackSize(obj->in);
	for (int i = 1; i < size; i++) {
		StackPush(obj->out, StackTop(obj->in));
		StackPop(obj->in);
	}
	int x = StackTop(obj->in);
	StackPop(obj->in);
	for (int i = 1; i < size; i++) {
		StackPush(obj->in, StackTop(obj->out));
		StackPop(obj->out);
	}
	return x;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	int size = StackSize(obj->in);
	for (int i = 1; i < size; i++) {
		StackPush(obj->out, StackTop(obj->in));
		StackPop(obj->in);
	}
	int x = StackTop(obj->in);
	for (int i = 1; i < size; i++) {
		StackPush(obj->in, StackTop(obj->out));
		StackPop(obj->out);
	}
	return x;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	if (StackEmpty(obj->in) == 0)
		return false;
	return true;
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(obj->in);
	StackDestroy(obj->out);
	obj->in = NULL;
	obj->out = NULL;
}
int main() {

	return 0;
}