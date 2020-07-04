#include<vector>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	TreeNode* prebuildTree(vector<int>& inorder, int* orderIdx, vector<int>& postorder, int start, int end) {
		TreeNode* root = new TreeNode(postorder[*orderIdx]);
		int rootidx = 0;
		while (root->val != inorder[rootidx]) {
			rootidx++;
		}
		if (rootidx < end) {
			--(*orderIdx);
			root->right = prebuildTree(inorder, orderIdx, postorder, rootidx + 1, end);
		}
		else
			root->right = nullptr;
		if (rootidx > start) {
			--(*orderIdx);
			root->left = prebuildTree(inorder, orderIdx, postorder, start, rootidx - 1);
		}
		else
			root->left = nullptr;
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.empty())
			return nullptr;
		int postIdx = postorder.size() - 1;
		return prebuildTree(inorder, &postIdx, postorder, 0, postorder.size() - 1);
	}
};
class Solution {
public:
	TreeNode* prebuildTree(vector<int>& inorder, int* orderIdx, vector<int>& postorder, int start, int end) {
		TreeNode* root = new TreeNode(inorder[*orderIdx]);
		int rootidx = 0;
		while (root->val != postorder[rootidx]) {
			rootidx++;
		}
		if (rootidx > start) {
			++(*orderIdx);
			root->left = prebuildTree(inorder, orderIdx, postorder, start, rootidx - 1);
		}
		else
			root->left = nullptr;
		if (rootidx < end) {
			++(*orderIdx);
			root->right = prebuildTree(inorder, orderIdx, postorder, rootidx + 1, end);
		}
		else
			root->right = nullptr;

		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty())
			return nullptr;
		int idx = 0;
		return prebuildTree(preorder, &idx, inorder, 0, inorder.size() - 1);
	}
};