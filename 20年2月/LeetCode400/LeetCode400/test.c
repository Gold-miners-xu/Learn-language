#include<stdio.h>
#include<math.h>
int findNthDigit(int n) {

	int bit = 1;
	long x = 9;
	while (n > x* bit) {
		n -= x * bit;
		x *= 10;
		bit++;
	}
	int rit = n % bit;
	int num = (n - 1) / bit + x / 9;
	while (rit > 1) {
		bit--;
		num %= (int)pow(10, bit);
		rit--;
	}
	if (rit == 0) {
		return num % 10;
	}
	printf("%d,%d,%d", rit, bit, num);
	rit = num / (int)pow(10, bit - 1);
	return rit;
}
int main() {
	return 0;
}