#include<string>
#include<iostream>
#include<sstream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:

	string tree2str(TreeNode* t) {
		string s;
		if (t) {
			stringstream str;
			str << t->val;
			s += str.str();
			if (t->left) {
				s += "(";
				s += tree2str(t->left);
				s += ")";
			}
			else {
				if (t->right)
					s += "()";
			}
			if (t->right) {
				s += "(";
				s += tree2str(t->right);
				s += ")";
			}
		}
		return s;
	}
};