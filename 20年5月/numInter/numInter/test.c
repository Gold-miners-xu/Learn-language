#include<stdio.h>
#include<string.h>
int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)
		return 0;
	int src = 0;
	int cont = 1;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != nums[src]) {
			src++;
			nums[src] = nums[i];
			cont++;
		}
	}
	numsSize = cont;
	return numsSize;
}
void QuickSort(int* a, int left, int rit) {

	if (left > rit)
		return;
	int tmp;
	int i = left, j = rit;
	for (; i < j;) {
		if (i < j && a[i] <= a[j]) {
			j--;
		}
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;

		for (; i < j && a[i] <= a[j];) {
			i++;
		}
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	QuickSort(a, left, i - 1);
	QuickSort(a, i + 1, rit);

}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	*returnSize = 0;
	int min, max;
	if (nums1Size > nums2Size) {
		min = nums2Size;
		max = nums1Size;
	}
	else {
		min = nums1Size;
		max = nums2Size;
	}
	int* rit = (int*)malloc(sizeof(int) * min);
	QuickSort(nums1, 0, nums1Size - 1);
	QuickSort(nums2, 0, nums2Size - 1);
	int i = 0, j = 0;
	int cont = 0;
	while (i < nums1Size && j < nums2Size) {
		if (nums1[i] < nums2[j]) {
			i++;
		}
		else if (nums1[i] > nums2[j]) {
			j++;
		}
		else {
			rit[cont] = nums2[j];
			i++;
			j++;
			cont++;
			(*returnSize)++;
		}
	}
	*returnSize = removeDuplicates(rit, *returnSize);
	return rit;
}