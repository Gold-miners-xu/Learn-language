#include<stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	static int x[2] = { 0 };
	*returnSize = 2;
	for (int i = 0; i < numsSize; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				x[1] = j;
				x[0] = i;
				return x;
			}
		}
	}
	printf("%d", x[0]);
	return 0;
}
int main() {
	return 0;
}