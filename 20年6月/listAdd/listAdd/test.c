#include<stdio.h>
#include<stdlib.h>
 struct ListNode {
	int val;
	struct ListNode* next;
	
};
 typedef struct ListNode Node;
 Node* flip(Node* head) {
	if (head->next == NULL) {
		return head;
	}
	Node* newhead = head;
	head = head->next;
	newhead->next = NULL;
	while (head != NULL) {
		if (head->val == 10) {
			free(head);
			break;
		}
		Node* tmp = newhead;
		newhead = head;
		head = head->next;
		newhead->next = tmp;
	}
	return newhead;
}

 Node* addTwoNumbers(Node* l1, Node* l2) {
	l1 = flip(l1);
	l2 = flip(l2);
	Node* newhead = (Node*)malloc(sizeof(Node));
	Node* tmp = newhead;
	int add = 0;
	while (l1 || l2) {
		tmp->val = l1->val + l2->val + add;
		if (tmp->val >= 10) {
			add = 1;
			tmp->val %= 10;
		}
		else {
			add = 0;
		}
		tmp->next = (Node*)malloc(sizeof(Node));
		tmp = tmp->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1) {
		tmp->val = l1->val + add;
		if (tmp->val >= 10) {
			add = 1;
			tmp->val %= 10;
		}
		else {
			add = 0;
		}
		l1 = l1->next;
		tmp->next = (Node*)malloc(sizeof(Node));
		tmp = tmp->next;
	}
	while (l2) {
		tmp->val = l2->val + add;
		if (tmp->val >= 10) {
			add = 1;
			tmp->val %= 10;
		}
		else {
			add = 0;
		}
		l2 = l2->next;
		tmp->next = (Node*)malloc(sizeof(Node));
		tmp = tmp->next;
	}
	if (add != 0) {
		tmp->val = add;
		tmp->next = NULL;
	}
	else {
		tmp->val = 10;
		tmp->next = NULL;
	}
	newhead = flip(newhead);
	return newhead;
}
int main() {
	Node* newhead1 = (Node*)malloc(sizeof(Node));
	Node* newhead2 = (Node*)malloc(sizeof(Node));
	newhead1->val = 1;
	newhead2->val = 2;
	newhead1->next = NULL;
	newhead2->next = NULL;
	addTwoNumbers(newhead1, newhead2);
	return 0;
}