#include<stdio.h>
long long minMoves(int* nums, int numsSize) {
	long long min = nums[0];
	long long max = nums[0];
	long long rit = 0;
	for (int i = 0; i < numsSize; i++) {
		if (min > nums[i]) {
			min = nums[i];
		}
		if (max < nums[i]) {
			max = nums[i];
		}
		rit += nums[i];
	}
	rit -= (min * numsSize);
	return rit;
}
int main() {
	int a[] = { 1,2,3 };
	minMoves(a, 3);
	return 0;
}