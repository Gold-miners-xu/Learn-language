#include<stdio.h>
int removeElement(int* nums, int numsSize, int val) {
	int sum = 0;
	if (numsSize == 0)
		return 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != val) {

			nums[sum] = nums[i];
			sum++;
		}

	}
	return sum;
}
int main() {
	int a[4] = { 3,2,2,3 };
	removeElement(a, 4, 3);
	return 0;
}