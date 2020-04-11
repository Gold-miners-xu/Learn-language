#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode* next;
	
};
typedef struct ListNode Node;

struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	Node* head1 = head;
	Node* head2 = head->next;
	Node* end1 = head;
	Node* end2 = head2;
	Node* tmp = head2->next;
	while (tmp != NULL) {
		end1->next = tmp;
		tmp = tmp->next;
		end1 = end1->next;
		if (tmp == NULL) {
			break;
		}
		end2->next = tmp;
		tmp = tmp->next;
		end2 = end2->next;
	}
	if (end1->next == end2) {
		end1->next = NULL;
	}
	else {
		end2->next = NULL;
	}
	tmp = head2;
	end1 = head1;
	end2 = head2;
	while (end1 != NULL && end2 != NULL) {
		end2 = end2->next;
		tmp->next = end1;
		tmp = tmp->next;
		if (end2 == NULL) {
			break;
		}
		end1 = end1->next;
		tmp->next = end2;
		tmp = tmp->next;
	}

	return head2;
}
int main() {

	return 0;
}