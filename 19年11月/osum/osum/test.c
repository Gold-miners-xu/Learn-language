#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int x;
	int a[100];
	int y;
	int sum = 0;
	printf("��������������ָ���(���ֵΪ100)\n");
	scanf("%d", &x);
	printf("����������\n");
	for (y = 0; y < x; y++) {
		scanf("%d", &a[y]);
		if (a[y] % 2 == 0) {
			sum += a[y];
		}
	}
	printf("ż����Ϊ%d", sum);
	return 0;
}