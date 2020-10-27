# include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	
};
vector<int> levelOrder(TreeNode* root) {
	vector<int> v;
	queue<TreeNode*> q;
	if (root) {
		q.push(root);
		v.push_back(root->val);
	}
	else
		return v;
	while (!q.empty()) {
		if (q.front()->left) {
			v.push_back(q.front()->left->val);
			q.push(q.front()->left);
		}
		if (q.front()->right) {
			v.push_back(q.front()->right->val);
			q.push(q.front()->right);
		}
		q.pop();
	}
	return v;
}