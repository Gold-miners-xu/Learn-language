#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;

};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == nullptr || l2 == nullptr)
		return (l1 == nullptr) ? l2 : l1;
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	head = (l1->val >= l2->val) ? l2 : l1;
	if (l1->val >= l2->val)
		l2 = l2->next;
	else
		l1 = l1->next;
	tail = head;
	while (l1 && l2) {
		tail->next = nullptr;
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
	if (l1 == nullptr)
		tail->next = l2;
	if (l2 == nullptr)
		tail->next = l1;

	return head;

}
ListNode* sortList(ListNode* head) {
	if (head == nullptr)
		return nullptr;
	int size = 0;
	ListNode* newNode = head;
	while (newNode) {
		newNode = newNode->next;
		size++;
	}
	int num = 1;
	while (num < size) {
		ListNode* node = head;
		ListNode* prev = nullptr;
		while (node != nullptr) {
			ListNode* head1 = node;
			ListNode* prev1 = nullptr;
			for (int i = 0; node != nullptr && i < num; i++) {
				prev1 = node;
				node = node->next;
			}
			if (prev1 != nullptr)
				prev1->next = nullptr;
			ListNode* head2 = node;
			ListNode* prev2 = nullptr;
			for (int j = 0; node != nullptr && j < num; j++) {
				prev2 = node;
				node = node->next;
			}
			if (prev2 != nullptr)
				prev2->next = nullptr;
			else
				continue;
			if (prev == nullptr)
				head = mergeTwoLists(head1, head2);
			else
				prev->next = mergeTwoLists(head1, head2);
			if (prev1->next == nullptr) {
				prev = prev1;
				prev1->next = node;
			}

			else {
				prev = prev2;
				prev2->next = node;
			}

		}
		num *= 2;
	}
	return head;
}
int main() {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->val = 4;
	head->next = (ListNode*)malloc(sizeof(ListNode));
	head->next->val = 2;
	head->next->next = (ListNode*)malloc(sizeof(ListNode));
	head->next->next->val = 1;
	head->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	head->next->next->next->val = 3;
	head->next->next->next->next = nullptr;
	sortList(head);
	return 0;
}