#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode* next;
	
};
typedef struct ListNode Node;
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	Node* end = head;
	for (int i = 0; i < n; i++) {
		end = end->next;
	}
	if (end == NULL) {
		Node* new = head;
		head = head->next;
		free(new);
		return head;
	}
	Node* del = head;
	while (end->next != NULL) {
		del = del->next;
		end = end->next;
	}
	Node* tmp = del->next;
	del->next = del->next->next;
	free(tmp);
	return head;
}
int main() {

	return 0;
}