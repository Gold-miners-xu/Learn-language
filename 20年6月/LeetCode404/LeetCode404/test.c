#include<stdio.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };


void add(int* rit, struct TreeNode* root) {
	if (root == NULL) {
		return;
	}
	if (root->left != NULL) {
		if (root->left->left == NULL && root->left->right == NULL) {
			(*rit) += root->left->val;
		}
	}

	add(rit, root->left);
	add(rit, root->right);
	return;

}
int sumOfLeftLeaves(struct TreeNode* root) {
	int rit = 0;
	add(&rit, root);
	return rit;
}