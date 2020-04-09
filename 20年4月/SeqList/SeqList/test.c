#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct SeqList
{
	int* array; // ָ��̬���ٵ�����
	size_t size; // ��Ч���ݸ���
	size_t capicity; // �����ռ�Ĵ�С
}SeqList;
// ������ɾ��Ľӿ�
// ˳����ʼ��
void SeqListInit(SeqList* psl, size_t capacity) {
	psl->array = (int*)malloc(sizeof(int) * 200);
	psl->size = 0;
	psl->capicity = 200;
}
// ˳�������
void SeqListDestory(SeqList* psl) {
	if (psl == NULL) {
		printf("˳�������,����ʧ��\n");
		return;
	}
	int yon;
	printf("�Ƿ�Ҫ����˳���? '1'��ʾȷ��,���������\n");
	scanf("%d", &yon);
	if (yon == 1) {
		free(psl->array);
		free(psl);
	}
}
// ˳����ӡ
void SeqListPrint(SeqList* psl) {
	if (psl == NULL)
		return;
	for (size_t i = 0; i < psl->size; i++) {
		printf("%d \n", psl->array[i]);
	}
	printf("��%d��Ԫ��\n", psl->size);
}
// ���ռ䣬������ˣ���������
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
// ˳���β��
void SeqListPushBack(SeqList* psl, int x) {
	if (psl == NULL) {
		printf("˳�������,β��ʧ��\n");
		return;
	}
	if (psl->capicity <= psl->size) {
		CheckCapacity(psl);
	}
	psl->array[psl->size] = x;
	psl->size++;
}
// ˳���βɾ
void SeqListPopBack(SeqList* psl) {
	if (psl == NULL) {
		printf("˳�������,ɾ��ʧ��\n");
		return;
	}
	if (psl->size == 0)
		return;
	else
		psl->size--;
}
// ˳���ͷ��
void SeqListPushFront(SeqList* psl, int x) {
	if (psl == NULL) {
		printf("˳�������,����ʧ��\n");
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
// ˳���ͷɾ
void SeqListPopFront(SeqList* psl) {
	if (psl == NULL) {
		printf("˳�������,ɾ��ʧ��\n");
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
// ˳������
int SeqListFind(SeqList* psl, int x) {
	if (psl == NULL) {
		printf("˳�������,����ʧ��\n");
		return INT_MAX;
	}
	for (size_t i = 0; i < psl->size; i++) {
		if (psl->array[i] == x)
			return i;
	}
	printf("δ�ҵ������Ԫ��\n");
	return INT_MAX;
}
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* psl, size_t pos, int x) {
	if (psl == NULL) {
		printf("˳�������,����ʧ��\n");
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
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* psl, size_t pos) {
	if (psl == NULL) {
		printf("˳�������,ɾ��ʧ��\n");
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
	SeqListInit(s, 200);//��ʼ��һ����������200��Ԫ�ص�˳���
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