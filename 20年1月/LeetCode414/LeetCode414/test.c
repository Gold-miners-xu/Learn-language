#include<stdio.h>
int thirdMax(int* nums, int numsSize) {
	int x = 0, y = -1, z = -1;
	for (int j = 0; j < numsSize; j++) {
		if (nums[j] > nums[x]) {
			x = j;
		}
	}
	for (int j = 0; j < numsSize; j++) {
		if (j == x) {
			continue;
		}
		if (y == -1 && nums[j] < nums[x]) {
			y = j;
		}
		if (nums[j] > nums[y] && nums[j] < nums[x]) {
			y = j;
		}
	}
	for (int j = 0; j < numsSize; j++) {
		if (j == x || j == y)
			continue;
		if (z == -1 && nums[j] < nums[x] && nums[j] < nums[y]) {
			z = j;
		}
		if (nums[j] > nums[z] && nums[j] < nums[x] && nums[j] < nums[y]) {
			z = j;
		}
	}
	if (numsSize == 1 || numsSize == 2)
		return nums[x];
	printf("%d", z);
	return nums[z];

}
int main() {
	int a[] = { 3,2,1 };
	thirdMax(a, 3);
	return 0;
}