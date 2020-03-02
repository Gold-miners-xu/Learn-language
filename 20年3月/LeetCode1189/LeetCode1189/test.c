#include<stdio.h>
int maxNumberOfBalloons(char* text) {
	int a = 0, b = 0, l = 0, o = 0, n = 0;
	int rit = 0;
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == 'a') {
			a++;
		}
		if (text[i] == 'b') {
			b++;
		}
		if (text[i] == 'l') {
			l++;
		}
		if (text[i] == 'o') {
			o++;
		}
		if (text[i] == 'n') {
			n++;
		}
	}
	l /= 2;
	o /= 2;
	rit = a;
	if (b < rit) {
		rit = b;
	}
	if (l < rit) {
		rit = l;
	}
	if (o < rit) {
		rit = o;
	}
	if (n < rit) {
		rit = n;
	}
	return rit;
}
int main() {
	return 0;
}