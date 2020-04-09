#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode* next;
	
};
typedef struct ListNode Node;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int count = 0;
	Node* p1 = l1;
	Node* p2 = l2;
	Node* head = (Node*)malloc(sizeof(Node));
	Node* tmp = head;
	Node* tail = NULL;
	while (p1 != NULL || p2 != NULL) {
		if (p1 != NULL && p2 != NULL) {
			tmp->val = p2->val + p1->val + count;
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1 == NULL) {
			tmp->val = p2->val + count;
			p2 = p2->next;
		}
		else if (p2 == NULL) {
			tmp->val = p1->val + count;
			p1 = p1->next;
		}
		if (tmp->val >= 10) {
			tmp->val -= 10;
			count = 1;
		}
		else {
			count = 0;
		}

		tmp->next = (Node*)malloc(sizeof(Node));
		tail = tmp;
		tmp = tmp->next;
	}
	if (count == 1) {
		tmp->val = 1;
		tmp->next = NULL;
	}
	else {
		free(tmp);
		tail->next = NULL;
	}
	//printf("%d",head->val);
	return head;
}
int main() {
	Node* head1 = (Node*)malloc(sizeof(Node));
	head1->val = 6;
	Node* head2 = (Node*)malloc(sizeof(Node));
	head2->val = 8;
	Node* newNode1 = (Node*)malloc(sizeof(Node));
	head1->next = newNode1;
	newNode1->val = 3;
	newNode1->next = NULL;
	Node* newNode2 = (Node*)malloc(sizeof(Node));
	head2->next = newNode2;
	newNode2->val = 7;
	newNode2->next = NULL;
	addTwoNumbers(head1, head2);
	return 0;
}