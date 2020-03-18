#include<stdio.h>
void merge(int* A, int ASize, int m, int* B, int BSize, int n) {
	int i = m, j = 0;
	while (i < ASize) {
		A[i] = B[j];
		i++;
		j++;
	}
	i = 0;
	while (i < ASize) {
		j = i + 1;
		while (j < ASize) {
			if (A[i] > A[j]) {
				int tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
			j++;
		}
		i++;
	}

}
int main() {

	return 0;
}