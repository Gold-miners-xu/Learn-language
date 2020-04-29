#include"treeNode.h"
#include"queue.h"
#include"stack.h"
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
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* res = BinaryTreeFind(root->_left, x);
	if (res)
		return res;
	res = BinaryTreeFind(root->_right, x);
	return res;
}
void BinaryTreePrevOrder(BTNode* root) {
	if (root) {
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
void BinaryTreeInOrder(BTNode* root) {
	if (root) {
		BinaryTreePrevOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_right);
	}
}
void BinaryTreePostOrder(BTNode* root) {
	if (root) {
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
		printf("%c ", root->_data);
	}
}
void BinaryTreeLevelOrder(BTNode* root) {
	Queue q;
	QueueInit(&q);
	if(root)
		QueuePush(&q, root);
	while (QueueEmpty(&q) == 0) {
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", tmp->_data);
		if (tmp->_left) {
			QueuePush(&q, tmp->_left);
		}
		if (tmp->_right) {
			QueuePush(&q, tmp->_right);
		}
	}
}
int BinaryTreeComplete(BTNode* root) {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (QueueEmpty(&q) == 0) {
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);
		if (tmp) {
			QueuePush(&q, tmp->_left);
			QueuePush(&q, tmp->_right);
		}
		else {
			break;
		}
	}
	while (QueueEmpty(&q) == 0) {
		BTNode* res = QueueFront(&q);
		QueuePop(&q);
		if (res)
			return 0;
	}
	return 1;
}
void BinaryTreePrevOrderno(BTNode* root) {
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	while (cur || StackEmpty(&s) == 0) {
		while (cur) {
			printf("%c ", cur->_data);
			StackPush(&s,cur);
			cur = cur->_left;
		}
		BTNode* tmp = StackTop(&s);
		StackPop(&s);
		cur = tmp->_right;
	}
}
void BinaryTreeInOrderno(BTNode* root) {
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	while (cur || StackEmpty(&s) == 0) {
		while (cur) {
			StackPush(&s, cur);
			cur = cur->_left;
		}
		BTNode* tmp = StackTop(&s);
		StackPop(&s);
		printf("%c ", tmp->_data);
		cur = tmp->_right;
	}
}
void BinaryTreePostOrderno(BTNode* root) {
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	BTNode* prev = NULL;
	while (cur || StackEmpty(&s) == 0) {
		while (cur) {
			StackPush(&s, cur);
			cur = cur->_left;
		}
		BTNode* tmp = StackTop(&s);
		if (tmp->_right == NULL || tmp->_right == prev) {
			printf("%c ", tmp->_data);
			StackPop(&s);
			prev = tmp;
		}
		else {
			cur = tmp->_right;
		}
		
		
	}
}
