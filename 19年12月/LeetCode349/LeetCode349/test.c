#include<stdio.h>
#include<string.h>
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

	int min, max;
	if (nums1Size > nums2Size) {
		min = nums2Size;
		max = nums1Size;
	}
	else {
		min = nums1Size;
		max = nums2Size;
	}
	int* rit = (int*)malloc(min * sizeof(int));
	int i, j;
	for (i = 0; i < min; i++) {
		for (j = 0; j < max; j++) {
			if (nums1[i] == nums2Size) {
				rit[(*returnSize)] = nums1[i];
				(*returnSize)++;
			}
		}
	}
	int k = 0;
	for (i = 0; i < *returnSize; i++) {
		for (j = i + 1; j < *returnSize; j++) {
			if (rit[i] == rit[j]) {
				k++;
				(*returnSize)--;
			}
		}
		rit[i] = rit[i + k];
	}
	return rit;
}
int main() {
	int a[4] = { 1,2,2,1 };
	int b[2] = { 2,2 };
	int returnSize = 0;
	intersection(a, 4, b, 2, &returnSize);
	return 0;

}