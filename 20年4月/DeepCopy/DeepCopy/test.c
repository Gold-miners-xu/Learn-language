#include<stdio.h>
#include<stdlib.h>
struct Node {
	int val;
	struct TreeNode* next;
	struct TreeNode* random;
	
};
typedef struct Node Node;
struct Node* copyRandomList(struct Node* head) {
	if (head == NULL) {
		return NULL;
	}
	Node* head1 = head;
	Node* rit = (Node*)malloc(sizeof(Node));
	Node* head2 = rit;
	while (head1->next != NULL) {
		head2->val = head1->val;
		head2->next = (Node*)malloc(sizeof(Node));
		head2 = head2->next;
		head1 = head1->next;
	}
	head2->val = head1->val;
	head2->next = NULL;
	head2 = rit;
	head1 = head;
	while (head1) {
		int i = 0;
		Node* next = head;
		if (head1->random == NULL) {
			head2->random = NULL;
		}
		else {
			while (next) {
				if (next == head1->random) {
					break;
				}
				else {
					next = next->next;
				}
				i++;
			}
			next = rit;
			for (int j = 0; j < i; j++) {
				next = next->next;
			}
			head2->random = next;
		}
		head1 = head1->next;
		head2 = head2->next;

	}
	return rit;
}
int main() {

	return 0;
}