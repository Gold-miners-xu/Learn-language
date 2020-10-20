#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	//TreeNode() : val(0), left(nullptr), right(nullptr) {}
	//TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	//TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};
TreeNode* inoreder(TreeNode* root) {
	TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
	newnode->left = nullptr;
	if (root != nullptr) {
		newnode->val = root->val;
		newnode->right = inoreder(root->left);
		TreeNode* next = newnode;
		while (next->right != nullptr) {
			next = next->right;
		}
		next->right = inoreder(root->right);
		free(root);
	}
	else {
		free(newnode);
		return nullptr;
	}
	return newnode;
}
void flatten(TreeNode* root) {
	TreeNode* ret = nullptr;
	if (root) {
		ret = inoreder(root);
		root = ret;
	}
}

int main() {
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->left = (TreeNode*)malloc(sizeof(TreeNode));
	root->left->val = 2;
	root->left->left = (TreeNode*)malloc(sizeof(TreeNode));
	root->left->left->val = 3;
	root->left->left->left = nullptr;
	root->left->left->right = nullptr;
	root->left->right = (TreeNode*)malloc(sizeof(TreeNode));
	root->left->right->val = 4;
	root->left->right->left = nullptr;
	root->left->right->right = nullptr;
	root->right = (TreeNode*)malloc(sizeof(TreeNode));
	root->right->val = 5;
	root->right->left = nullptr;
	root->right->right = (TreeNode*)malloc(sizeof(TreeNode));
	root->right->right->val = 6;
	root->right->right->left = nullptr;
	root->right->right->right = nullptr;
	root->val = 1;
	flatten(root);
	return 0;
}