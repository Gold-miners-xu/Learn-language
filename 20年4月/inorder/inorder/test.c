#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	struct Node* left;
	struct Node* right;
	char val;

} Node;

Node* Init(char* str, int* std) {
	if (str[*std] != '#') {
		Node* root = (Node*)malloc(sizeof(Node));
		root->val = str[*std];
		(*std)++;
		root->left = Init(str, std);
		(*std)++;
		root->right = Init(str, std);
		return root;

	}
	else {
		return NULL;
	}
}
void inorder(Node* root) {
	if (root) {
		inorder(root->left);
		printf("%c ", root->val);
		inorder(root->right);
	}


}
int main() {
	char str[101];
	scanf("%s", str);
	int std = 0;
	Node* root = Init(str, &std);
	inorder(root);
	return 0;
}
