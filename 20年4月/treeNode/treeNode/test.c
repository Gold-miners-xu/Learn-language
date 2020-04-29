#include"treeNode.h"
void test() {
	char a[] = "abc##de#g##f###";
	int x = 0;
	BTNode* root = BinaryTreeCreate(a, &x);
	printf("%d ", BinaryTreeSize(root));
	printf("%d ",BinaryTreeLeafSize(root));
	printf("%d ", BinaryTreeLevelKSize(root,5));
	BTNode* res = BinaryTreeFind(root, 'x');
	BinaryTreeLevelOrder(root);
	BinaryTreeComplete(root);
	BinaryTreePrevOrderno(root);
	BinaryTreeInOrderno(root);
	BinaryTreePostOrderno(root);
}
int main() {
	test();
	return 0;
}