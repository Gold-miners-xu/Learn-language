#include<stdio.h>
void sort(int* A, int left, int rit) {
	if (left > rit)
		return;
	int tmp;
	int i = left, j = rit;
	for (; i < j;) {
		if (i < j && A[i] <= A[j]) {
			j--;
		}
		tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;

		for (; i < j && A[i] <= A[j];) {
			i++;
		}
		tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}
	sort(A, left, i - 1);
	sort(A, i + 1, rit);
}
int* sortedSquares(int* A, int ASize, int* returnSize) {
	for (int i = 0; i < ASize; i++) {
		A[i] = A[i] * A[i];
	}
	sort(A, 0, ASize - 1);
	*returnSize = ASize;
	return A;
}
int main() {
	int x = 0;
	int a[] = { -4,-1,0,3,10 };
	sortedSquares(a, 5, &x);
	return 0;
}