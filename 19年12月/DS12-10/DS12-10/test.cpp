#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode Node;
struct ListNode {
	int val;
	struct ListNode* next;
	
};
bool hasCycle(struct ListNode* head) {
	if (head == NULL)
		return false;
	Node* next1 = head->next;
	if (next1 == NULL)
		return false;
	Node* next2 = next1->next;
	while (next2 != NULL) {
		if (next2->next == head)
			return true;
		next1->next = head;
		next1 = next2;
		next2 = next1->next;
	}
	return false;
}
int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	Node* next = (Node*)malloc(sizeof(Node));
	head->val = 1;
	next->val = 2;
	head->next = next;
	next->next = head;
	hasCycle(head);
	return 0;
}