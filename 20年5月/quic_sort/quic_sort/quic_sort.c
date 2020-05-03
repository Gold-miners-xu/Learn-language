#include"quic_sort.h"
void swap(int* arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
void quic1(int* arr, int i, int j) {
	if (i >= j) {
		return;
	}
	int left = i;
	int end = j;
	while (left < end) {
		while(left < end) {
			if (arr[left] > arr[end]) {
				swap(arr, left, end);
				break;
			}
			end--;
		}
		while (left < end) {
			if(arr[left] > arr[end]) {
				swap(arr, left, end);
				break;
			}
			left++;
		}
		
	}
	quic1(arr, i, left - 1);
	quic1(arr, left + 1, j);
}