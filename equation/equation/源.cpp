#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main() {
	int sn = 0, i,sum = 0;
	scanf("%d", &i);
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			sum = sum+pow(10, y) * i;
		}
		sn += sum;
	}
	printf("sn=%d", sn);
	return 0;
}