#include<stdio.h>
int singleNumber(int* nums, int numsSize) {
	long x = 0;
	int rit = 0;
	for (int i = 0; i < numsSize; i++) {
		rit ^= nums[i];
	}
	return rit;
}
int main() {
	return 0;
}