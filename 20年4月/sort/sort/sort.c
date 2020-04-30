#include"sort.h"

void swap(int* arr, int x, int y) {
	int tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
}
void selsort(int* arr, int size) {
	int min;
	for (int i = 0; i < size - 1; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		swap(arr, min, i);

	}
}
