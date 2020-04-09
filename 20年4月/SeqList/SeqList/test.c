#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct SeqList
{
	int* array; // 指向动态开辟的数组
	size_t size; // 有效数据个数
	size_t capicity; // 容量空间的大小
}SeqList;
// 基本增删查改接口
// 顺序表初始化
void SeqListInit(SeqList* psl, size_t capacity) {
	psl->array = (int*)malloc(sizeof(int) * 200);
	psl->size = 0;
	psl->capicity = 200;
}
// 顺序表销毁
void SeqListDestory(SeqList* psl) {
	if (psl == NULL) {
		printf("顺序表不存在,销毁失败\n");
		return;
	}
	int yon;
	printf("是否要销毁顺序表? '1'表示确认,任意键返回\n");
	scanf("%d", &yon);
	if (yon == 1) {
		free(psl->array);
		free(psl);
	}
}
// 顺序表打印
void SeqListPrint(SeqList* psl) {
	if (psl == NULL)
		return;
	for (size_t i = 0; i < psl->size; i++) {
		printf("%d \n", psl->array[i]);
	}
	printf("共%d个元素\n", psl->size);
}
// 检查空间，如果满了，进行增容
void CheckCapacity(SeqList* psl) {
	if (psl->capicity == psl->size) {
		int* fe = psl->array;
		psl->array = (int*)malloc(sizeof(int) * psl->capicity * 2);
		for (size_t i = 0; i < psl->size; i++) {
			psl->array[i] = fe[i];
		}
		psl->capicity *= 2;
		free(fe);
	}
	
}
// 顺序表尾插
void SeqListPushBack(SeqList* psl, int x) {
	if (psl == NULL) {
		printf("顺序表不存在,尾插失败\n");
		return;
	}
	if (psl->capicity <= psl->size) {
		CheckCapacity(psl);
	}
	psl->array[psl->size] = x;
	psl->size++;
}
// 顺序表尾删
void SeqListPopBack(SeqList* psl) {
	if (psl == NULL) {
		printf("顺序表不存在,删除失败\n");
		return;
	}
	if (psl->size == 0)
		return;
	else
		psl->size--;
}
// 顺序表头插
void SeqListPushFront(SeqList* psl, int x) {
	if (psl == NULL) {
		printf("顺序表不存在,插入失败\n");
		return;
	}
	if (psl->capicity <= psl->size) {
		CheckCapacity(psl);
	}
	for (size_t i = psl->size; i > 0; i--) {
		psl->array[i] = psl->array[i - 1];

	}
	psl->array[0] = x;
	psl->size++;
}
// 顺序表头删
void SeqListPopFront(SeqList* psl) {
	if (psl == NULL) {
		printf("顺序表不存在,删除失败\n");
		return;
	}
	if (psl->size == 0) {
		return;
	}
	
	for (size_t i = 0; i < psl->size - 1; i++) {
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
// 顺序表查找
int SeqListFind(SeqList* psl, int x) {
	if (psl == NULL) {
		printf("顺序表不存在,查找失败\n");
		return INT_MAX;
	}
	for (size_t i = 0; i < psl->size; i++) {
		if (psl->array[i] == x)
			return i;
	}
	printf("未找到需查找元素\n");
	return INT_MAX;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* psl, size_t pos, int x) {
	if (psl == NULL) {
		printf("顺序表不存在,插入失败\n");
		return;
	}
	if (pos >= psl->size)
		return;
	if (psl->capicity <= psl->size) {
		CheckCapacity(psl);
	}
	for (size_t i = psl->size; i > pos; i--) {
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[pos] = x;
	psl->size++;

}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, size_t pos) {
	if (psl == NULL) {
		printf("顺序表不存在,删除失败\n");
		return;
	}
	if (pos >= psl->size)
		return;
	for (size_t i = pos; i < psl->size; i++) {
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
int main() {
	SeqList* s = (SeqList*)malloc(sizeof(SeqList));
	SeqListInit(s, 200);//初始化一个可以容纳200个元素的顺序表
	SeqListPushBack(s, 1);
	SeqListPushBack(s, 2);
	SeqListPushBack(s, 3);
	SeqListPushBack(s, 4);
	SeqListPushFront(s, 5);
	SeqListPushFront(s, 6);
	SeqListPushFront(s, 7);
	SeqListPrint(s);
	printf("%d\n", SeqListFind(s, 7));
	SeqListPopBack(s);
	SeqListPopBack(s);
	SeqListPrint(s);
	SeqListPopFront(s);
	SeqListPopFront(s);
	SeqListPrint(s);
	SeqListDestory(s);

	return 0;
}