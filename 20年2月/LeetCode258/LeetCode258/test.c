#include<stdio.h>
int add(int num) {
	int rit = 0;
	while (num > 9) {
		rit += (num % 10);
		num /= 10;
	}
	rit += num;
	return rit;
}
int addDigits(int num) {
	if (num <= 9) {
		return num;
	}
	while (num > 9) {
		num = add(num);
	}
	return num;
}
int main() {
	return 0;
}