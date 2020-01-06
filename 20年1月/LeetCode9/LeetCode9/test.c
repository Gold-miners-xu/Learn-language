#include<stdio.h>
#include<math.h>

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	int sum = x;
	long y = 0;
	while (sum != 0) {
		int tmp = 0;
		tmp = sum % 10;
		y = y * 10 + tmp;
		sum /= 10;

	}
	if (x == y)
		return true;
	return false;
}

int main() {
	isPalindrome(121);
	return 0;
}