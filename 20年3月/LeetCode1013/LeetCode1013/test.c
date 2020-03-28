#include<stdio.h>
#define false 0
#define true 1
int canThreePartsEqualSum(int* A, int ASize) {
	int num = 0;
	for (int i = 0; i < ASize; i++) {
		num += A[i];
	}
	if (num % 3 != 0) {
		return false;
	}
	int rit = num / 3;
	int x = 0;
	num = 0;
	for (int j = 0; j < ASize; j++) {
		num += A[j];
		if (num == rit) {
			num = 0;
			x++;
		}
		if (x == 2 && j < ASize - 1) {
			return true;
		}
	}
	return false;

}
int main() {
	int a[] = { 0,2,1,-6,6,-7,9,1,2,0,1 };
	canThreePartsEqualSum(a, sizeof(a) / sizeof(int));
	return 0;
}