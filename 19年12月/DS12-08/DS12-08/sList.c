#include "sList.h"


void SListPrint(SListNode* pList) {
	SListNode* cur = pList;
	while (cur != NULL) {
		printf("%d->", cur->data);
		cur = cur->next;

	}
	printf("NULL");
}//��ӡ����
void SListPushBack(SListNode** ppList, SLTDataType x) {
	SListNode* newNode = BuyListNode(x);
	if (*ppList == NULL) {
		*ppList = newNode;
	}
	else {
		SListNode* tail = *ppList;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newNode;
	}
	


}//β��
SListNode* BuyListNode(SLTDataType x) {
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}//�����½ڵ�
void SListPushFront(SListNode** ppList, SLTDataType x) {
	SListNode* newNode = BuyListNode(x);
		newNode->next = *ppList;
		*ppList = newNode;


}//ͷ��
void SListPopBack(SListNode** ppList) {

	if (*ppList == NULL) {
		return;
	}
	else if ((*ppList)->next == NULL) {
		free(*ppList);
		*ppList = NULL;
	}
	else {
		SListNode* tail = *ppList;
		SListNode* prev = NULL;
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		free(tail);

		prev->next = NULL;
	}

}//βɾ
void SListPopFront(SListNode** ppList) {
	if (*ppList == NULL) {
		return;

	}
	else {
		SListNode* tmp = (*ppList)->next;
		free(*ppList);
		*ppList = tmp;
	}


}//ͷɾ
SListNode* SListfind(SListNode* pList, SLTDataType x) {
	SListNode* cur = pList;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		else {
			cur = cur->next;
		}
	}
}//��

void SListInsertAfter(SListNode* pos, SLTDataType x) {
	SListNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
	

}//��
void SListEraseAfter(SListNode* pos) {
	SListNode* next = pos->next;
	if (next != NULL) {
		pos->next = next->next;
		free(next);
	}
}
void SListDestory(SListNode** ppList) {
	SListNode* cur = *ppList;
	while (cur)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*ppList = NULL;
}