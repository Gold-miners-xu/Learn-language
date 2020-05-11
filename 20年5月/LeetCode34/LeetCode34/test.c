#include<stdio.h>
#include<string.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int* rit = (int*)malloc(sizeof(int) * 2);
	rit[0] = -1;
	rit[1] = -1;
	if (numsSize == 0) {
		return rit;
	}
	int left = 0, right = numsSize - 1;
	int mid = (left + right) / 2;
	while (right > left) {
		mid = (left + right) / 2;
		if (nums[mid] >= target)
			right = mid;
		else
			left = mid + 1;
	}
	if (nums[left] != target)
		return rit;
	rit[0] = left;
	right = numsSize;
	while (right > left) {
		mid = (left + right) / 2;
		if (nums[mid] <= target)
			left = mid + 1;
		else
			right = mid;
	}
	rit[1] = right - 1;
	*returnSize = 2;
	return rit;
}
int main() {
	int a[] = { 4,5,8,8,9,10 };
	int size;
	searchRange(a, 6, 8, &size);
	return 0;
}