#include<stdio.h>
bool isMonotonic(int* A, int ASize) {
	if (ASize <= 1)
		return true;
	int a = 0;
	int b = 0;
	for (int i = 1; i < ASize; i++) {
		if (A[i] <= A[i - 1])
			a++;
		if (A[i] >= A[i - 1])
			b++;
		if (i != a && i != b)
			return false;

	}

	return true;
}
int main() {
	return 0;
}