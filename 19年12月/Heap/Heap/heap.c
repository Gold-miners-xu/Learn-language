#include<stdio.h>
#include<assert.h>
#include<string.h>
#include <stdlib.h>
#include"heap.h"
// �ѵĹ���(���鴴��)
void HeapCreate(Heap* hp, HPDataType* a, int n) {
	assert(hp && a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	int i = 0;
	for (i = 0; i < n; ++i) {
		hp->_a[i] = a[i];
	}
	//����,���һ��������ʼ����
	for (i = (n - 2) / 2; i >= 0; --i) {
		ShiftDown(hp->_a, n, i);
	}
	hp->_size = hp->_capacity = n;
}
void HeapInit(Heap* hp) {
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
//��������
void Swap(HPDataType* pa, HPDataType* pb) {
	HPDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;

}
//����Ϊ�����,���µ���(���ڵ���������Ϊ�����)
void ShiftDown(HPDataType* a, int n, int root) {
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;
	//��ǰ�ڵ��Ƿ��к���
	while (child < n) {
		//�Ƿ��к���,�����,������ѡ���
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		//�����Ƿ���ڸ���
		if (a[child] > a[parent]) {
			//�������Ӻ͸���
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			//�������
			break;
		}

	}
}
// �ѵ�����
void HeapDestory(Heap* hp) {
	if (hp->_a) {
		free(hp->_a);
		hp->_a = NULL;
		hp->_size = hp->_capacity = 0;
	}
}
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x) {
	assert(hp);
	if (hp->_size == hp->_capacity) {
		int newC = hp->_capacity == 0 ? 10 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, newC * sizeof(HPDataType));
		hp->_capacity = newC;
	}
	hp->_a[hp->_size] = x;
	hp->_size = hp->_size + 1;
	//���ϵ���
	int i = hp->_size - 1;
	while (i > 0 && hp->_a[i] > hp->_a[(i - 1) / 2]) {
		Swap(&hp->_a[i], &hp->_a[(i - 1) / 2]);
		i = (i - 1) / 2;
	}

}
// �Ѷ���ɾ��
void HeapPop(Heap* hp) {
	assert(hp);
	if (hp->_size <= 1) {
		hp->_size = 0;

	}
	else {
		hp->_a[0] = hp->_a[hp->_size - 1];
		hp->_size = hp->_size - 1;
		ShiftDown(hp->_a, hp->_size, 0);
	}
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp) {
	assert(hp && hp->_size);
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp) {
	assert(hp);
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp) {
	assert(hp);
	if (hp->_size == 0)
		return 1;
	return 0;
}
// ��������ж�����(�����)
//void HeapSort(int* a, int n) {
//	if (n == 0)
//		return;
//	Heap hp;
//	HeapCreate(&hp, a, n);
//
//}
//��ӡ����
void HeapPrint(Heap* hp) {
	assert(hp);
	for (int i = 0; i < hp->_size; ++i) {
		printf("%d", hp->_a[i]);
	}
	printf("\n");
}
//void TestHeap() {
//	int a[] = { 1,5,3,8,7,6 };
//	//����֮��{8,7,6,5,1,3}
//	Heap hp;
//	HeapCreate(&hp, a, sizeof(a) / sizeof(int));
//	HeapPrint(&hp);
//}
void TestHeap() {
	Heap hp;
	HeapInit(&hp);
	HeapPush(&hp, 1);
	HeapPush(&hp, 2);
	HeapPush(&hp, 3);
	HeapPush(&hp, 4);
	HeapPush(&hp, 5);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);

}
int main() {
	TestHeap();
	return 0;
}