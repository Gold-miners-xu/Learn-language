#include<stdio.h>
int majorityElement(int* nums, int numsSize) {
	int num = nums[0];
	int sum = 1;
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] != num) {
			sum--;
		}
		else {
			sum++;
		}
		if (sum <= 0) {
			num = nums[i];
			sum++;
		}
	}
	return num;
}
int main() {

	return 0;
}