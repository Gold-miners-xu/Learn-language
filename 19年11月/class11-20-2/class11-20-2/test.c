#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int recursive(int n,int m) {
	if (n == 1)
		return m;
	return n * recursive(n - 1, m);
}//递归求m的n次方
int cursive(int n, int m) {
	int sum;
	for ( sum = 1; n > 0; n--) {
		sum *= m;
		
	}
	return sum;
}//非递归求m的n次方
int main() {
	int x, y;
	//scanf("%d%d", &x, &y);
	//printf("%d",recursive(x, y));//调用递归函数
	scanf("%d%d", &x, &y);
	printf("%d", cursive(x, y));//调用非递归函数
	return 0;
}