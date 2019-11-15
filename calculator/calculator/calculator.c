#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
double add(double a, double b) {
	return a + b;
}
double subtract(double a, double b) {
	return a - b;
}
double multiply(double a, double b) {
	return a * b;
}
double divide(double a, double b) {
	return a / b;
}
double power(double a, double b) {
	return pow(a, b);
}
double rooting(double a,double b) {
	return pow(a, 1 / b);
}

int main() {
	double x, y;
	char s[2];
	scanf("%lf", &x);
	for (; 1;) {
		scanf("%s%lf", &s[0], &y);
		if (s[0] == '=')
			break;
		else if (s[0] == '+')
			x = add(x, y);
		else if (s[0] == '-')
			x = subtract(x, y);
		else if (s[0] == '*')
			x = multiply(x, y);
		else if (s[0] == '/')
			x = divide(x, y);
		else if (s[0] == 'p')
			x = power(x, y);
		else if (s[0] == 'r')
			x = rooting(x,y);
		else
			printf(" ‰»Î”–ŒÛ");
		

	}
	printf("=%f", x);
	return 0;

}