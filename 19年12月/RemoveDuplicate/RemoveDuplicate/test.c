#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode* next;
};
typedef struct ListNode Node;
struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (head == NULL)
		return NULL;
	Node* node1 = head;
	Node* node2 = head->next;
	while (node2 != NULL) {
		if (node1->val == node2->val) {
			Node* tmp = node2->next;
			free(node2);
			node2 = tmp;
			node1->next = node2;
			continue;
		}
		if (node1->val != node2->val) {
			node1 = node2;
			node2 = node1->next;
		}
	}
	return head;

}
int main() {

	return 0;
}