#include<stdio.h>
void QuickSort(int* a, int left, int rit) {

	if (left > rit)
		return;
	int tmp;
	int i = left, j = rit;
	for (; i < j;) {
		while (i < j && a[i] <= a[j]) {
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
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize) {
	if (arrSize == 0) {
		return NULL;
	}
	QuickSort(arr, 0, arrSize - 1);
	int* rit = (int*)malloc(sizeof(int) * k);
	for (int i = 0; i < arrSize && i < k; i++) {
		rit[i] = arr[i];
	}
	*returnSize = k;
	return rit;
}
int main() {

	return 0;
}