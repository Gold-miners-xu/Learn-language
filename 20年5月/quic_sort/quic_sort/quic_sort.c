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
void quic2(int* arr, int i, int j) {
	if (i >= j) {
		return;
	}
	int left = i;
	int end = j;
	while (left < end) {
		while (left < end && arr[i] <= arr[end])
			end--;
		while (left < end && arr[i] >= arr[left])
			left++;
		swap(arr, left, end);

	}
	swap(arr, i, left);
	quic2(arr, i, left - 1);
	quic2(arr, left + 1, j);
}
void quic3(int* arr, int i, int j) {
	if (i >= j) {
		return;
	}
	int cur = i + 1;
	int prev = i;
	while (cur <= j) {
		if (arr[cur] < arr[i] && ++prev != cur)
			swap(arr, prev, cur);
		cur++;
	}
	swap(arr, i, prev);
	quic3(arr, i, prev - 1);
	quic3(arr, prev + 1, j);
}