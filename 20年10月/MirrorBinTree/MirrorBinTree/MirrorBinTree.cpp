
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	
};
bool istrue(TreeNode* root1, TreeNode* root2) {
	if (root1 && root2) {
		if (root1->val != root2->val)
			return false;
		if (!istrue(root1->left, root2->right))
			return false;
		if (!istrue(root1->right, root2->left))
			return false;
	}
	else if (root1 || root2) {
		return false;
	}
	return true;
}
//判断二叉树是否为对称二叉树
bool isSymmetric(TreeNode* root) {
	if (!root)
		return true;
	return istrue(root->left, root->right);
}
//生成二叉树的镜像
TreeNode* mirrorTree(TreeNode* root) {
	if (root) {
		TreeNode* tmp = root->left;
		root->left = mirrorTree(root->right);
		root->right = mirrorTree(tmp);
	}
	return root;
}