#include"sort_heap.h"
void swap(int* arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
void down(int* val, int parent, int size) {
	int child = parent * 2 + 1;

	while (child < size) {
		if (child + 1 < size && val[child] > val[child + 1]) {
			child++;
		}
		if (val[child] < val[parent]) {
			swap(val, child, parent);
		}
		else {
			break;
		}
		parent = child;
		child = parent * 2 + 1;
	}

}
void sort_heap(int* arr, int size) {
	int parent = (size - 2) / 2;
	while (parent >= 0) {
		down(arr, parent, size);
		parent--;
	}
	while (size > 0) {
		swap(arr, 0, size - 1);
		size--;
		down(arr, 0, size);
		
	}
}