#include"sort_mer.h"

void Mer(int* arr, int begin, int mid, int end, int* tmp) {
	int n1 = begin;
	int n2 = mid + 1;
	int idx = begin;
	while (n1 <= mid && n2 <= end) {
		if (arr[n1] <= arr[n2]) {
			tmp[idx] = arr[n1];
			idx++;
			n1++;
		}
		else {
			tmp[idx] = arr[n2];
			idx++;
			n2++;
		}
	}
	if (n1 != mid + 1) {
		memcpy(tmp + idx, arr + n1, sizeof(int) * (mid - n1 + 1));
	}
	else if (n2 != end + 1) {
		memcpy(tmp + idx, arr + n2, sizeof(int) * (end - n2 + 1));
	}
	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}
void sortMer(int* arr, int size) {
	int k = 1;
	int* tmp = (int*)malloc(sizeof(int) * size);
	while (k < size) {
		for (int i = 0; i < size; i += k) {
			int begin = i;
			int mid = i + k - 1;
			if (mid >= size - 1)
				break;
			int end = i + (2 * k);
			if (end >= size)
				end = size - 1;
			Mer(arr, begin, mid, end, tmp);
		}
		k *= 2;
	}
	
}