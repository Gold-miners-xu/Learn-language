#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode* next;
	
};
typedef struct ListNode Node;
struct ListNode* detectCycle(struct ListNode* head) {
	if (head == NULL)
		return NULL;
	Node* quick = head;
	if (quick->next == NULL)
		return NULL;
	Node* slow = head;
	while (quick != NULL && quick->next != NULL) {
		quick = quick->next->next;
		slow = slow->next;
		if (quick == slow) {
			slow = slow->next;
			int k = 1;
			while (quick != slow) {
				slow = slow->next;
				k++;
			}
			quick = head;

			while (quick != slow) {

				for (int i = 0; i < k; i++) {
					if (quick == slow)
						return quick;
					slow = slow->next;

				}
				quick = quick->next;
			}
			return quick;
		}
	}
	return NULL;

}
int main() {
	Node* head;
	detectCycle(head);

	return 0;
}