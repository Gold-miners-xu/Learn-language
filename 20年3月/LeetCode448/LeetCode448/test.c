#include<stdio.h>
#include<string.h>
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
	int* a = (int*)malloc(sizeof(int) * numsSize);
	int* b = (int*)malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		int x = nums[i];
		a[x - 1] = 1;
	}
	int k = 0, j;
	for (j = 0; j < numsSize; j++) {
		if (a[j] != 1) {
			b[k] = j + 1;
			k++;
		}
	}
	*returnSize = k;
	return b;
}
int main() {
	int a[] = { 4,3,2,7,8,2,3,1 };
	int b;
	findDisappearedNumbers(a, 8, &b);
	return 0;
}