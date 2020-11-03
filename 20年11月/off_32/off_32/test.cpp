#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> ret;
	stack<TreeNode*> s;
	if (root)
		s.push(root);
	int size = 0;
	while (!s.empty()) {
		vector<TreeNode*> tmp;
		size++;
		ret.resize(size);
		while (!s.empty()) {
			if (size % 2 != 0) {
				if (s.top()->left) {
					tmp.push_back(s.top()->left);
				}
				if (s.top()->right) {
					tmp.push_back(s.top()->right);
				}
			}
			else {
				if (s.top()->right) {
					tmp.push_back(s.top()->right);
				}
				if (s.top()->left) {
					tmp.push_back(s.top()->left);
				}
			}
			ret[size - 1].push_back(s.top()->val);
			s.pop();
		}
		if (tmp.size() == 0)
			break;
		for (auto i : tmp)
			s.push(i);
	}
	return ret;
}