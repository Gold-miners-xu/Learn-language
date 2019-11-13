#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int triangle(int a, int b, int c) {
	if (a < b + c && b < a + c && c < a + b)
		return 1;
	return 0;
}
int main() {
	int a, b, c;
	double s, p;
	scanf("%d%d%d", &a, &b, &c);
	int i = triangle(a, b, c);
	if (i) {
		p = (a + b + c) / 2.0;
		printf("%f\n", p);
		s = pow((p * (p - a) * (p - b) * (p - c)), 0.5);
		printf("%f\n", s);
	}
	return;
}