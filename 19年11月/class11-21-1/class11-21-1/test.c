#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int add(int n) {
	int x,sum = 0;
	for (; 1;) {
		x = n % 10;
		
		sum += x;
		if (n < 10)
			break;
		n /= 10;
	}
	if (sum > 9)
		return add(sum);
	return sum;
}
int main() {
	int x[100] = { 1 };
	for (int i = 0; 1;i++) {
		scanf("%d", x+i);
		if (x[i] == 0)
			break;
		
	}
	for (int j = 0; x[j] != 0; j++) {
		printf("%d\n", add(x[j]));
	}
	return 0;
}