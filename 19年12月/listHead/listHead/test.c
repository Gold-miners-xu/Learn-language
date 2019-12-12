#include"listHead.h"
int main() {
	ListNode* plist = ListCreate();
	ListPushFront(plist, 1);
	ListPushFront(plist, 0);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPrint(plist);
	ListNode* two = ListFind(plist, 2);
	ListNode* five = ListFind(plist, 5);
	ListInsert(plist, 4);
	ListPrint(plist);
	ListPopBack(plist);
	ListPopFront(plist);
	ListErase(plist->_next);
	ListPrint(plist);

	return 0;
}