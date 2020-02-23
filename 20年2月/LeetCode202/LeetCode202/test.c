#include<stdio.h>
bool isHappy(int n) {

	while (n != 1) {
		int x = 0;
		while (n > 9) {
			x += (n % 10) * (n % 10);
			n /= 10;
		}
		x += (n * n);
		//printf("%d",n);
		n = x;
		if (n == 4)
			return false;
	}
	return true;
}
int main() {
	return 0;
}