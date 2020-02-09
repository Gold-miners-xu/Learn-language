#include<stdio.h>
#include<string.h>
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
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	(*returnSize) = 0;
	if (nums1Size > 0 && nums2Size > 0) {
		QuickSort(nums1, 0, nums1Size - 1);
		QuickSort(nums2, 0, nums2Size - 1);
	}
	else
		return NULL;
	int max, min;
	if (nums1Size > nums2Size) {
		max = nums1Size;
		min = nums2Size;
	}
	else {
		max = nums2Size;
		min = nums1Size;
	}
	int* rit = (int*)malloc(sizeof(int) * min);
	int i = 0, j = 0;
	while (i < nums1Size && j < nums2Size) {
		if (nums1[i] > nums2[j]) {
			j++;
		}
		else if (nums2[j] > nums1[i]) {
			i++;
		}
		else {
			rit[(*returnSize)] = nums1[i];
			i++;
			j++;
			(*returnSize)++;
		}
	}
	return rit;
}
int main() {
	return 0;
}