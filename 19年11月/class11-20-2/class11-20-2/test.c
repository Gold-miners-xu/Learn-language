#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int recursive(int n,int m) {
	if (n == 1)
		return m;
	return n * recursive(n - 1, m);
}//�ݹ���m��n�η�
int cursive(int n, int m) {
	int sum;
	for ( sum = 1; n > 0; n--) {
		sum *= m;
		
	}
	return sum;
}//�ǵݹ���m��n�η�
int main() {
	int x, y;
	//scanf("%d%d", &x, &y);
	//printf("%d",recursive(x, y));//���õݹ麯��
	scanf("%d%d", &x, &y);
	printf("%d", cursive(x, y));//���÷ǵݹ麯��
	return 0;
}