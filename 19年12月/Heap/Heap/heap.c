#include<stdio.h>
#include<assert.h>
#include<string.h>
#include <stdlib.h>
#include"heap.h"
// 堆的构建(数组创建)
void HeapCreate(Heap* hp, HPDataType* a, int n) {
	assert(hp && a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	int i = 0;
	for (i = 0; i < n; ++i) {
		hp->_a[i] = a[i];
	}
	//调整,最后一棵子树开始调整
	for (i = (n - 2) / 2; i >= 0; --i) {
		ShiftDown(hp->_a, n, i);
	}
	hp->_size = hp->_capacity = n;
}
void HeapInit(Heap* hp) {
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
//交换函数
void Swap(HPDataType* pa, HPDataType* pb) {
	HPDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;

}
//调整为大根堆,向下调整(根节点两子树都为大根堆)
void ShiftDown(HPDataType* a, int n, int root) {
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;
	//当前节点是否有孩子
	while (child < n) {
		//是否有孩子,如果有,两者中选最大
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		//孩子是否大于父亲
		if (a[child] > a[parent]) {
			//交换孩子和父亲
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			//调整完毕
			break;
		}

	}
}
// 堆的销毁
void HeapDestory(Heap* hp) {
	if (hp->_a) {
		free(hp->_a);
		hp->_a = NULL;
		hp->_size = hp->_capacity = 0;
	}
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x) {
	assert(hp);
	if (hp->_size == hp->_capacity) {
		int newC = hp->_capacity == 0 ? 10 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, newC * sizeof(HPDataType));
		hp->_capacity = newC;
	}
	hp->_a[hp->_size] = x;
	hp->_size = hp->_size + 1;
	//向上调整
	int i = hp->_size - 1;
	while (i > 0 && hp->_a[i] > hp->_a[(i - 1) / 2]) {
		Swap(&hp->_a[i], &hp->_a[(i - 1) / 2]);
		i = (i - 1) / 2;
	}

}
// 堆顶的删除
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
// 取堆顶的数据
HPDataType HeapTop(Heap* hp) {
	assert(hp && hp->_size);
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp) {
	assert(hp);
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp) {
	assert(hp);
	if (hp->_size == 0)
		return 1;
	return 0;
}
// 对数组进行堆排序(大根堆)
//void HeapSort(int* a, int n) {
//	if (n == 0)
//		return;
//	Heap hp;
//	HeapCreate(&hp, a, n);
//
//}
//打印函数
void HeapPrint(Heap* hp) {
	assert(hp);
	for (int i = 0; i < hp->_size; ++i) {
		printf("%d", hp->_a[i]);
	}
	printf("\n");
}
//void TestHeap() {
//	int a[] = { 1,5,3,8,7,6 };
//	//调整之后{8,7,6,5,1,3}
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