#include<stdio.h>
int getSum(int a, int b) {
	int sum = a ^ b;
	int carry;
	carry = ((unsigned int)(a & b)) << 1;
	if (carry != 0) {
		return getSum(sum, carry);
	}
	return sum;
}