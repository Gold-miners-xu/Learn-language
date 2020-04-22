#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};

int getH(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int l = 0;
	l += getH(root->left);
	int r = 0;
	r += getH(root->right);
	return  l > r ? l + 1 : r + 1;
}
int main() {

	return 0;
}