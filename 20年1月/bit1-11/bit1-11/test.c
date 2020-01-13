#include<stdio.h>
int searchInsert(int* nums, int numsSize, int target) {
	if (target == 0) {
		return 0;
	}
	int i;
	for (i = 0; i < numsSize; i++) {
		if (target <= nums[i])
			return i;
	}
	return i;
}
int main() {
	int s[3][4] = { "1,2,2","2,3,4","5,6,7" };

	return 0;
}