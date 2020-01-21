#include<stdio.h>
#include<string.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int* rit = (int*)malloc(sizeof(int) * (digitsSize + 1));
	int cat = 10;
	for (int i = digitsSize - 1; i >= 0; i--) {
		if (digits[i] == 9 && cat == 10) {
			rit[i + 1] = 0;
		}
		if (digits[i] != 9 && cat == 10) {
			rit[i + 1] = digits[i] + 1;
			cat = 0;
			continue;
		}
		if (cat == 0) {
			rit[i + 1] = digits[i];
		}
	}
	if (rit[1] == 0) {
		rit[0] = 1;
		*returnSize = digitsSize + 1;
		return rit;
	}
	else {
		*returnSize = digitsSize;
		return rit + 1;
	}
}
int main() {
	int a[] = { 1,2,3 };
	int x = 0;
	plusOne(a, 3, &x);
	return 0;
}