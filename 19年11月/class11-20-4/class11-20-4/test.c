	#define _CRT_SECURE_NO_WARNINGS
	#include<stdio.h>
	int prime(int n) {
		for (int i = 2; i < n; i++)
			if (n % i == 0)
				return 0;
		return 1;
	}
	int main() {
		int x;
		scanf("%d", &x);
		printf("%d", prime(x));
		return 0;
	}