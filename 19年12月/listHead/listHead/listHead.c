#include"listHead.h"
ListNode* ListCreate() {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;
	return head;
}
// �������������ͷ���.
void ListDestory(ListNode* plist) {
	if (plist == NULL)
		return;
	ListNode* head = plist;
	ListNode* next = plist->_next;
	while (next != head) {
		free(plist);
		plist = next;
		next = plist->_next;

	}
	free(plist);
}// ˫����������
void ListPrint(ListNode* plist) {
	if (plist == NULL || plist->_next == plist)
		return;
	ListNode* next = plist->_next;
	while (next != plist) {
		printf("%d<->", next->_data);
		next = next->_next;
	}
	printf("\n");
}// ˫�������ӡ
void ListPushBack(ListNode* plist, LTDataType x) {
	if (plist == NULL)
		return;
	ListNode* tail = plist->_prev;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_prev = tail;
	newnode->_data = x;
	newnode->_next = plist;
	tail->_next = newnode;
	plist->_prev = newnode;

}// ˫������β��

ListNode* ListFind(ListNode* plist, LTDataType x) {
	if (plist == NULL || plist->_next == NULL)
		return NULL;
	ListNode* find = plist->_next;
	while (find->_data != x && find != plist) {
		find = find->_next;
	}
	if (find->_data == x)
		return find;
	return NULL;
}// ˫���������
void ListInsert(ListNode* pos, LTDataType x) {
	if (pos == NULL)
		return;
	ListNode* prev = pos->_prev;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	newnode->_next = pos;
	newnode->_prev = prev;
	pos->_prev = newnode;
	prev->_next = newnode;
}// ˫��������pos��ǰ����в���
void ListPopBack(ListNode* plist) {
	if (plist == NULL || plist->_next == NULL)
		return;
	ListNode* tail = plist->_prev;
	ListNode* prev = tail->_prev;
	free(tail);
	prev->_next = plist;
	plist->_prev = prev;
}
// ˫������βɾ

void ListPushFront(ListNode* plist, LTDataType x) {
	if (plist == NULL)
		return;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	ListNode* next = plist->_next;
	newnode->_data = x;
	newnode->_next = next;
	newnode->_prev = plist;
	plist->_next = newnode;
	next->_prev = newnode;
}
// ˫������ͷ��

void ListPopFront(ListNode* plist) {
	if (plist == NULL || plist->_next == NULL)
		return;
	ListNode* next = plist->_next;
	ListNode* tmp = next->_next;
	free(next);
	plist->_next = tmp;
	tmp->_prev = plist;
}
// ˫������ͷɾ

void ListErase(ListNode* pos) {
	if (pos == NULL)
		return;
	ListNode* next = pos->_next;
	ListNode* prev = pos->_prev;
	free(pos);
	next->_prev = prev;
	prev->_next = next;
}
//˫������ɾ��posλ�õĽڵ�