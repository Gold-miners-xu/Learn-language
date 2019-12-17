#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode* next;
	
};
int getlen(struct ListNode* head) {
	int len = 0;
	struct ListNode* cur = head;
	while (cur) {
		len++;
		cur = cur->next;
	}
	return len;
}
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	if (headA == NULL || headB == NULL)
		return NULL;
	int lenA = getlen(headA);
	int lenB = getlen(headB);
	int longer = lenA >= lenB ? lenA : lenB;
	int shorter = lenA < lenB ? lenA : lenB;
	int diff = longer - shorter;
	struct ListNode* quick = lenA >= lenB ? headA : headB;
	struct ListNode* low = lenA < lenB ? headA : headB;
	while (diff) {
		quick = quick->next;
		diff--;
	}
	while (quick != NULL && low != NULL) {
		if (quick == low) {
			return quick;
		}
		else {
			quick = quick->next;
			low = low->next;
		}
	}
	return NULL;
}
int main() {
	

	getlen(head);
	return 0;
}