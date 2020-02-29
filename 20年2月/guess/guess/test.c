#include<stdio.h>
int ARoN(int x) {
	if (x != 0) {
		return 0;
	}
	return 1;
}
int BRoN(int x) {
	if (x == 2) {
		return 0;
	}
	return 1;
}
int CRoN(int x) {
	if (x == 3) {
		return 0;
	}
	return 1;
}
int DRoN(int x) {
	if (x != 3) {
		return 0;
	}
	return 1;
}
int main() {
	int x;
	x = 0;
	if (ARoN(x) + BRoN(x) + CRoN(x) + DRoN(x) == 1)
		printf("A是凶手");
	x = 1;
	if (ARoN(x) + BRoN(x) + CRoN(x) + DRoN(x) == 1)
		printf("B是凶手");
	x = 2;
	if (ARoN(x) + BRoN(x) + CRoN(x) + DRoN(x) == 1)
		printf("C是凶手");
	x = 3;
	if (ARoN(x) + BRoN(x) + CRoN(x) + DRoN(x) == 1)
		printf("A是凶手");
	return 0;
}