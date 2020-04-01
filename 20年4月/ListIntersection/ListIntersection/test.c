#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode* next;
	
};
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	if (headA == NULL || headB == NULL) {
		return NULL;
	}
	struct ListNode* A = headA;
	struct ListNode* B = headB;
	while (headA != headB) {
		if (headA == NULL) {
			headA = A;
		}
		else {
			headA = headA->next;
		}
		if (headB == NULL) {
			headB = B;
		}
		else {
			headB = headB->next;
		}
	}
	return headB;
}
int main() {

	return 0;
}