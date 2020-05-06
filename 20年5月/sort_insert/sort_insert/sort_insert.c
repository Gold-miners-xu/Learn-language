#include"sort_insert.h"
void swap(int* arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
void sortInsert(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j;
		for (j = i - 1;j >= 0 && key < arr[j]; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}