#include<stdio.h>


typedef struct ListNode {
	int val;
	struct ListNode* next;
} ListNode;
 ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return pHead;
	ListNode* prev = NULL;
	ListNode* cur = pHead;
	ListNode* next = pHead->next;
	while (next != NULL) {
		if (next->val == cur->val) {
			while (next != NULL && next->val == cur->val) {
				next = next->next;
			}
			while (cur != next) {
				ListNode* tmp = cur;
				cur = cur->next;
				free(tmp);
			}
			if (prev == NULL) {
				pHead = next;

			}
			else {
				prev->next = next;
			}


			if (next != NULL) {
				next = cur->next;
			}

		}

		else {
			prev = cur;
			cur = next;
			next = next->next;
		}

	}
	return pHead;
}
int main() {

	return 0;
}