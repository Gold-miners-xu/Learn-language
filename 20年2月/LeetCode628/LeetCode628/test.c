#include<stdio.h>
void QuickSort(int* a, int left, int rit) {

	if (left > rit)
		return;
	int tmp;
	int i = left, j = rit;
	while (i < j) {
		while (i < j && a[i] <= a[j]) {
			j--;
		}
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;

		while (i < j && a[i] <= a[j]) {
			i++;
		}
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	QuickSort(a, left, i - 1);
	QuickSort(a, i + 1, rit);

}
int maximumProduct(int* nums, int numsSize) {
	QuickSort(nums, 0, numsSize - 1);
	int max;
	if (nums[0] * nums[1] * nums[numsSize - 1] > nums[numsSize - 3] * nums[numsSize - 1] * nums[numsSize - 2]) {
		max = nums[0] * nums[1] * nums[numsSize - 1];
	}
	else
		max = nums[numsSize - 3] * nums[numsSize - 1] * nums[numsSize - 2];
	return max;

}
int main() {
	return 0;
}