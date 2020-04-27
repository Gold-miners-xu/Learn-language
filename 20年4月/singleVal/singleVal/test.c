#include<stdio.h>
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};
bool isSingle(struct TreeNode* root, int val) {
	if (root == NULL)
		return true;
	return root->val == val
		&& isSingle(root->left, val)
		&& isSingle(root->right, val);
}

bool isUnivalTree(struct TreeNode* root) {
	if (root == NULL)
		return true;
	return isSingle(root, root->val);
}