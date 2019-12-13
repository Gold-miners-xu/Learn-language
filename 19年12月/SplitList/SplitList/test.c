#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
	
};
typedef struct ListNode Node;
struct ListNode* partition(struct ListNode* head, int x) {
	if (head == NULL)
		return NULL;
	Node* cur = head->next;
	Node* head2 = NULL;
	if (head->val >= x) {
		head2 = head;
		head = NULL;
	}
	Node* tail1 = head;
	Node* tail2 = head2;
	while (cur != NULL) {
		if (cur->val < x) {
			if (head == NULL) {
				head = cur;
				tail1 = head;
				cur = cur->next;
			}
			else {
				tail1->next = cur;
				cur = cur->next;
				tail1 = tail1->next;
			}
		}
		else {
			if (head2 == NULL) {
				head2 = cur;
				tail2 = head2;
				cur = cur->next;
			}
			else {
				tail2->next = cur;
				tail2 = tail2->next;
				cur = cur->next;
			}
		}
	}
	if (tail2 == NULL) {
		tail1->next = NULL;
		return head;
	}
	else if (tail1 == NULL) {
		tail2->next = NULL;
		return head2;
	}
	else {
		tail1->next = head2;
		tail2->next = NULL;
		return head;
	}


}
//将链表根据x的值分为两份,小于x的值放在链表前面,
//大于等于x的值放在链表后面,不改变链表的其他顺序
int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	partition(head, 5);
	return 0;
}