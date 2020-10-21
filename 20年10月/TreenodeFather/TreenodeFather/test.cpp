#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};
TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q, int& flag) {
	int num = flag;
	if (root) {
		if (q == root || p == root)
			flag++;
		TreeNode* ret;
		ret = find(root->left, p, q, flag);
		if (ret)
			return ret;
		ret = find(root->right, p, q, flag);
		if (ret)
			return ret;
		if (flag - num == 2)
			return root;
	}
	return nullptr;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	int flag = 0;
	TreeNode* ret = find(root, p, q, flag);
	return ret;
}