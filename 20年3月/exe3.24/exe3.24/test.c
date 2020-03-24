#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//void exe() {
//	int a, b;
//
//	scanf("%d %d", &a, &b);
//	int rit = a;
//	for (int i = a + 1; i < b; i++) {
//		rit &= i;
//	}
//	printf("%d\n", rit);
//}
//int main() {
//	while (1) {
//		exe();
//	}
//	return 0;
//}
//
int Prime(int n) {
	for (int i = 2; i < n / 2; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
void exe2() {
	int n;
	scanf("%d", &n);
	int num = 0;
	int rit = 0;
	for (int i = 1; i <= n;i++) {
		if (Prime(i)) {
			num += i;
		}
		if(num > )
	}
}
int main() {
	while (1) {
		exe2;
	}
	return 0;
}