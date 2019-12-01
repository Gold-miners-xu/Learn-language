#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void YHTriangle(int n,int a[20]) {
	a[0] = 1;
	printf(" 1\n");
	for (int i = 1; i < n; i++) {
		int j;
		for (j = i; j >= 0; j--) {
			if (j == 0) {
				a[j] = 1;
			}
			else
			a[j] += a[j - 1];
		}
		for (int k = 0; k <= i; k++) {
			printf(" %d", a[k]);
		}
		printf("\n");
	}
}
int main() {
	int i;
	int a[20] = { 1 };
	printf("请输入杨辉三角层数(小于20)\n");
	scanf("%d", &i);
	YHTriangle(i,a);
	return 0;
}