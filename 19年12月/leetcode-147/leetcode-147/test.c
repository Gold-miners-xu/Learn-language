#include<stdio.h>
#include<string.h>
struct ListNode {
	int val;
	struct ListNode* next;
	
};
typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	Node* sorted = head;
	Node* next = head->next;
	head->next = NULL;
	while (next != NULL) {
		if (sorted->val > next->val) {
			head = next;
			next = next->next;
			head->next = sorted;
			sorted = head;
		}
		else {
			while (sorted->next != NULL && sorted->next->val <= next->val) {
				sorted = sorted->next;
			}
			if (sorted->next == NULL) {
				sorted->next = next;
				next = next->next;
				sorted->next->next = NULL;
				sorted = head;
			}
			else {
				Node* tmp = next->next;
				next->next = sorted->next;
				sorted->next = next;
				next = tmp;
				sorted = head;
			}
		}
	}
	return head;

}
int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	Node* next1 = (Node*)malloc(sizeof(Node));
	Node* next2 = (Node*)malloc(sizeof(Node));
	Node* next3 = (Node*)malloc(sizeof(Node));
	head->val = 4;
	next1->val = 2;
	next1->val = 1;
	next3->val = 3;
	head->next = next1;
	next1->next = next2;
	next2->next = next3;
	next3->next = NULL;
	insertionSortList(head);
	return 0;
}
//����ռ�����ֽ�
//���ַ����뷽ʽ���
//ʹ��һ������ı���ʾ����,ÿ�����ֺ�һ�����ֶ�Ӧ
//1.GBK:windows��������Ĭ�ϰ�,�����ֽ�һ������
//2.UTF-8:LinuxĬ�ϱ��뷽ʽ,�䳤����,һ���������ֽ�(ȫ����ͨ��).
//����=>���뷽ʽ��ͳһ.
//