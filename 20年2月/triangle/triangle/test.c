#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main() {
	int x;
	scanf("%d", &x);
	int* res = (int*)malloc(sizeof(int) * x);
	int* rit = (int*)malloc(sizeof(int) * x);
	int i = 0;
	while (i < x) {
		for (int j = 0; j < i; j++) {
			if (i % 2 == 0) {
				if (j == 0 || j == (i - 1)) {
					rit[j] = 1;
					printf("1 ");
					continue;
				}
				printf("%d ", res[j] + res[j - 1]);
				rit[j] = res[j] + res[j - 1];
			}
			else {
				if (j == 0 || j == (i - 1)) {
					res[j] = 1;
					printf("1 ");
					continue;
				}
				printf("%d ", rit[j] + rit[j - 1]);
				res[j] = rit[j] + rit[j - 1];
			}
		}
		printf("\n");
		i++;
	}

	return 0;
}