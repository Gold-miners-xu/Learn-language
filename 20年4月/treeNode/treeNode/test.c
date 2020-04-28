#include"treeNode.h"
void test() {
	char a[] = "abc##de#g##f###";
	int x = 0;
	BTNode* root = BinaryTreeCreate(a, &x);
	printf("%d ", BinaryTreeSize(root));
	printf("%d ",BinaryTreeLeafSize(root));
	printf("%d ", BinaryTreeLevelKSize(root,5));
}
int main() {
	test();
	return 0;
}