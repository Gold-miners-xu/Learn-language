#include<stdio.h>
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};
bool isEq(struct TreeNode* a, struct TreeNode* b) {
	if (a == NULL && b == NULL)
		return true;
	if (a == NULL || b == NULL)
		return false;
	return a->val == b->val
		&& isEq(a->left, b->left)
		&& isEq(a->right, b->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (s == NULL)
		return false;
	return isEq(s, t)
		|| isSubtree(s->left, t)
		|| isSubtree(s->right, t);
}