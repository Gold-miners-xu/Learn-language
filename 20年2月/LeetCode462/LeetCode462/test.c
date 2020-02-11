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
int minMoves2(int* nums, int numsSize) {
	QuickSort(nums, 0, numsSize - 1);
	int median = 0;
	if (numsSize % 2 == 0) {
		median = nums[numsSize / 2] + nums[(numsSize / 2) - 1];
		median /= 2;
	}
	else {
		median = nums[numsSize / 2];
	}
	int num = 0;
	for (int i = 0; i < numsSize; i++) {
		if (median > nums[i]) {
			num += (median - nums[i]);
		}
		else {
			num += (nums[i] - median);
		}
	}
	return num;
}
int main() {
	return 0;
}