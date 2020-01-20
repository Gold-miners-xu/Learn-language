#include<stdio.h>
#include<math.h>
int pivotIndex(int* nums, int numsSize) {
	if (numsSize == 0)
		return -1;
	int left = 0, rit = 0;
	for (int i = 0; i < numsSize; i++) {
		rit += nums[i];
	}
	for (int j = 0; j < numsSize; j++) {
		rit -= nums[j];
		if (left == rit) {
			return j;
		}

		left += nums[j];
	}
	return -1;
}
int main() {
	int a[] = { -1,-1,-1,-1,0,1 };
	pivotIndex(a, 6);
	return 0;
}