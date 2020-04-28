#include"treeNode.h"
BTNode* BinaryTreeCreate(BTDataType* str, int* std) {
	if (str[*std] != '#') {
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = str[*std];
		(*std)++;
		root->_left = BinaryTreeCreate(str, std);
		(*std)++;
		root->_right = BinaryTreeCreate(str, std);
		return root;

	}
	else {
		return NULL;
	}
}
void BinaryTreeDestory(BTNode** root) {
	if (*root) {
		BinaryTreeDestory(&(*root)->_left);
		BinaryTreeDestory(&(*root)->_right);
		free(*root);
		*root = NULL;
	}
}
void BTsize(BTNode* root, int* size) {
	if (root) {
		BTsize(root->_left, size);
		BTsize(root->_right, size);
		(*size)++;
	}
}
int BinaryTreeSize(BTNode* root) {
	int size = 0;
	BTsize(root, &size);
	return size;
}
void BTLsize(BTNode* root, int* size) {
	if (root) {
		BTLsize(root->_left,size);
		BTLsize(root->_right,size);
		if (root->_left == NULL && root->_right == NULL) {
			(*size)++;
		}
	}
}
int BinaryTreeLeafSize(BTNode* root) {
	int size = 0;
	BTLsize(root, &size);
	return size;
}
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root && k != 1) {
		k--;
		return BinaryTreeLevelKSize(root->_left, k) +
			BinaryTreeLevelKSize(root->_right, k);
	}
	else if (root && k == 1) {
		return 1;
	}
	else 
		return 0;
	
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {

}
