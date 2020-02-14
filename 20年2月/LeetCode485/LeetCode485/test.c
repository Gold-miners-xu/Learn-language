#include<stdio.h>
int findMaxConsecutiveOnes(int* nums, int numsSize) {
	int max = 0;
	int num = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != 1) {
			num = 0;
		}
		else {
			num++;
		}
		if (num > max) {
			max = num;
		}
	}
	return max;
}
int main() {
	return 0;
}