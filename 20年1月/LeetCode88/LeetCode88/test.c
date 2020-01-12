#include<stdio.h>
void sort(int* nums, int numsSize) {
	for (int i = 0; i < numsSize; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] > nums[j]) {
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
	}
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

	for (int i = m, j = 0; i < m + n; i++, j++) {
		nums1[i] = nums2[j];
	}
	sort(nums1, m + n);
}
int main() {
	return 0;
}