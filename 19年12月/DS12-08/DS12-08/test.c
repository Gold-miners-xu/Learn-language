#include "sList.h"

int main() {
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushFront(&pList, 0);

	SListPrint(pList);
	printf("\n");
	SListPopBack(&pList);
	SListPopBack(&pList);
	//SListPopBack(&pList);
	//SListPopBack(&pList); 
	SListPrint(pList);
	printf("\n");
	SListPopFront(&pList);
	//SListPopFront(&pList);
	//SListPopFront(&pList);
	//SListPopFront(&pList);
	SListEraseAfter(pList);
	SListPrint(pList);

	return 0;
}