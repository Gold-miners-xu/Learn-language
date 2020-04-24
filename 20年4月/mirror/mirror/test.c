#include<stdio.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};

bool isReverseEq(struct TreeNode* a, struct TreeNode* b) {
	if (a == NULL && b == NULL)
		return true;
	if (a == NULL || b == NULL)
		return false;
	return a->val == b->val
		&& isReverseEq(a->left, b->right)
		&& isReverseEq(a->right, b->left);
}

bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;
	return isReverseEq(root->left, root->right);
}
