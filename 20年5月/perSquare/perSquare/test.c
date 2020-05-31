#include<stdio.h>
#include<stdlib.h>

bool isPerfectSquare(int num) {
	int tmp = 1;
	long sum = 0;
	if (num < 1) {
		return false;
	}
	while (sum < num) {
		sum += tmp;
		tmp += 2;
	}
	if (sum == num) {
		return true;
	}
	return false;
}
int main() {

	return 0;
}