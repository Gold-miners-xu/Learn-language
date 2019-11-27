#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int x;
	int a[100];
	int y;
	int sum = 0;
	printf("请输入待输入数字个数(最大值为100)\n");
	scanf("%d", &x);
	printf("请输入数字\n");
	for (y = 0; y < x; y++) {
		scanf("%d", &a[y]);
		if (a[y] % 2 == 0) {
			sum += a[y];
		}
	}
	printf("偶数和为%d", sum);
	return 0;
}