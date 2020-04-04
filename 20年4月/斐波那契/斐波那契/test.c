#include<stdio.h>
int fib(int N) {
	if (N == 0) {
		return 0;
	}
	if (N <= 1) {
		return 1;
	}
	int n = 1;
	int m = 1;
	for (int i = 2; i < N; i++) {
		if (i < N) {
			n = m + n;
			i++;
		}
		if (i < N) {
			m = n + m;
		}
	}
	if (m > n) {
		return m;
	}
	return n;
}
int main() {

	return 0;
}