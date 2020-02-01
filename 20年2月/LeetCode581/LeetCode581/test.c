#include<stdio.h>
int findUnsortedSubarray(int* nums, int numsSize) {
	int rit = numsSize;
	int r = -1, l = -1;
	for (int i = 0; i < numsSize; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] > nums[j]) {
				r = i;
				break;
			}
		}
		if (r != -1) {
			break;
		}
	}
	for (int x = numsSize - 1; x >= 0; x--) {
		for (int y = x - 1; y >= 0; y--) {
			if (nums[y] > nums[x]) {
				l = x;
				break;
			}
		}
		if (l != -1) {
			break;
		}
	}
	if (l == -1 && r == -1)
		return 0;
	rit = rit - r - numsSize + l + 1;
	printf("%d,%d", r, l);
	return rit;
}
int main() {
	return 0;
}