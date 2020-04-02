#include<stdio.h>
int search(int* nums, int numsSize, int target) {

	if (numsSize == 0) {
		return 0;
	}
	int left = 0, rit = numsSize - 1;
	int mid = (rit + left) / 2;
	int res = 0;
	while (left < rit) {

		if (nums[mid] > target) {
			rit = mid;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else {
			break;
		}
		mid = (rit + left) / 2;
	}
	if (nums[mid] == target) {
		res++;
	}
	if (res == 0) {
		return 0;
	}
	int Goleft = mid - 1;
	int Gorit = mid + 1;
	while (Goleft >= 0) {
		if (nums[Goleft] == target) {
			res++;
			Goleft--;
		}
		else {
			break;
		}
	}
	while (Gorit < numsSize) {
		if (nums[Gorit] == target) {
			res++;
			Gorit++;
		}
		else {
			break;
		}
	}
	return res;
}
int main() {
	int a[] = { 1,4 };
	search(a, 2, 4);
	return 0;
}