#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode* next;
	
};

int numComponents(struct ListNode* head, int* G, int GSize) {
	if (GSize == 0)
		return 1;
	int count = 0;
	int tag = 0;
	while (head) {
		int i = 0;
		for (; i < GSize; i++) {
			if (G[i] == head->val && tag == 0) {
				count++;
				tag = 1;
				break;
			}
			else if (G[i] == head->val)
				break;
		}
		if (i == GSize)
			tag = 0;
		head = head->next;
	}
	return count;
}
int main() {

	return 0;
}
