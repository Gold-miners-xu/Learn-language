#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void traverse(int n) {
	if (n > 9)
		traverse(n / 10);
	printf("%d ", n % 10);
}
int main() {
	int i = 0;
	scanf("%d", &i);

	traverse(i);
	return 0;
}