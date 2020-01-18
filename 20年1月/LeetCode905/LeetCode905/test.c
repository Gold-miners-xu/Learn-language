#include<stdio.h>
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
	int* rit = (int*)malloc(sizeof(int) * ASize);
	*returnSize = ASize;
	int left = 0;
	int right = ASize - 1;
	int i = 0;
	while (i < ASize) {
		if (A[i] % 2 == 0) {
			rit[left] = A[i];
			i++;
			left++;
		}
		else {
			rit[right] = A[i];
			i++;
			right--;
		}
	}
	return rit;
}
int main() {

	return 0;
}