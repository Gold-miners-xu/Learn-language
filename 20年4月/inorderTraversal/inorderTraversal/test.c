#include<stdio.h>
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};
int getSize(struct TreeNode* root) {
	if (root == NULL) {
		return 0;

	}
	return getSize(root->left) + getSize(root->right) + 1;
}
void Init(struct TreeNode* root, int* rit, int* size) {
	if (root) {
		Init(root->left, rit, size);
		rit[*size] = root->val;
		(*size)++;
		Init(root->right, rit, size);
	}
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int* rit = (int*)malloc(sizeof(int) * getSize(root));
	*returnSize = 0;
	Init(root, rit, returnSize);
	return rit;
}
int main() {

	return 0;
}