#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode* next;
	
};
typedef struct ListNode Node;

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL || l2 == NULL)
		return (l1 == NULL) ? l2 : l1;
	Node* head = NULL;
	Node* tail = NULL;
	head = (l1->val >= l2->val) ? l2 : l1;
	if (l1->val >= l2->val)
		l2 = l2->next;
	else
		l1 = l1->next;
	tail = head;
	while (l1 && l2) {
		tail->next = NULL;
		if (l1->val < l2->val) {
			tail->next = l1;
			tail = l1;
			l1 = l1->next;
		}
		else {
			tail->next = l2;
			tail = l2;
			l2 = l2->next;

		}
	}
	if (l1 == NULL)
		tail->next = l2;
	if (l2 == NULL)
		tail->next = l1;

	return head;

}
int main() {
	return 0;
}