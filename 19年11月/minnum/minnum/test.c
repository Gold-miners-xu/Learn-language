#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void minnum(int n, int k, int a[], int b[]) {
	for (int i = 0; i < k; i++) {
		*(b+i) = a[i];
	}
	for (int j = k; j < n; j++) {
		for (int t = 0; t < k; t++) {
			if (b[t] > a[j])
				b[t] = a[j];
		}
	}
}
int main() {
	int n, k;
	int a[100];
	int b[100];
	printf("请分别输入要输入的数组个数(小于100)和需要求的最小数\n");
	scanf("%d %d", &n, &k);
	printf("请输入数组\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	minnum(n, k, a, b);
	for (int i = 0; i < k; i++) {
		printf("%d\n", b[i]);

}
	return 0;
}