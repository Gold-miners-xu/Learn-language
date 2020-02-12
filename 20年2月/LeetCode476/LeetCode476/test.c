#include<stdio.h>
int findComplement(int num) {
	if (num < 2)
		return 0;
	long long x = 2;
	while (num > (x - 1)) {
		x *= 2;
	}
	return x - 1 - num;
}
int main() {
	return 0;
}