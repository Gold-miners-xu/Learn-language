#include<stdio.h>
int findKthLargest(int* nums, int numsSize, int k) {
	int i = 0;
	while (i < k) {
		for (int j = i; j < numsSize; j++) {

			if (nums[i] < nums[j]) {
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
		i++;
	}
	return nums[k - 1];
}
int main() {
	return 0;
}