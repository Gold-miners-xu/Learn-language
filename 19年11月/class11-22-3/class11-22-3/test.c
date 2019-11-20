#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void recursive(int n) {
	if (n > 9)
		recursive(n / 10);//不断调用自身
	printf("%d ",n % 10);
}//递归打印每一位数
int main() {
	int x;
	scanf("%d", &x);
	recursive(x);
	return 0;
}