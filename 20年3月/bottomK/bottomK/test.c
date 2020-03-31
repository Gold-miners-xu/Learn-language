#include<stdio.h>
typedef struct ListNode {
	int val;
	struct ListNode* next;
} ListNode;
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode* pList = pListHead;
	for (int i = 0; i < k; i++) {
		if (pList == NULL) {
			return NULL;
		}
		pList = pList->next;

	}
	ListNode* K = pListHead;
	while (pList) {
		K = K->next;
		pList = pList->next;
	}
	return K;
}
int main() {
	return 0;
}