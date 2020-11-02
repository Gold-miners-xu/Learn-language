#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};
bool cmp(TreeNode* A, TreeNode* B) {
	if (B) {
		if (!A)
			return false;
		if (A->val != B->val)
			return false;
		if (!cmp(A->left, B->left))
			return false;
		if (!cmp(A->right, B->right))
			return false;
	}
	return true;
}
bool inorder(TreeNode* A, TreeNode* B) {
	if (A) {
		if (A->val == B->val && cmp(A, B))
			return true;
		if (inorder(A->left, B))
			return true;
		if (inorder(A->right, B))
			return true;
	}
	return false;
}
bool isSubStructure(TreeNode* A, TreeNode* B) {
	if (!B)
		return false;
	return inorder(A, B);
}