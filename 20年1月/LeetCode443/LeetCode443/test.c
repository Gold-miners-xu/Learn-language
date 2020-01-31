#include<stdio.h>
int math(int x, char* chars, int* j) {
	if (x > 999) {
		chars[(*j)++] = (x / 1000) + '0';
		x %= 1000;
		chars[(*j)++] = (x / 100) + '0';
		x %= 100;
		chars[(*j)++] = (x / 10) + '0';
		x %= 10;
		chars[(*j)++] = x + '0';
		return;
	}
	if (x > 99) {
		chars[(*j)++] = (x / 100) + '0';
		x %= 100;
		chars[(*j)++] = (x / 10) + '0';
		x %= 10;
		chars[(*j)++] = x + '0';
		return;
	}
	if (x > 9) {
		chars[(*j)++] = (x / 10) + '0';
		x %= 10;
		chars[(*j)++] = x + '0';
		return;
	}
	chars[(*j)++] = x + '0';
	return;
}
int compress(char* chars, int charsSize) {
	if (charsSize == 0)
		return 0;
	int j = 0;
	for (int i = 0; i < charsSize;) {
		chars[j] = chars[i];
		j++;
		i++;
		int size = 1;
		while (i < charsSize && chars[i] == chars[i - 1]) {
			size++;
			i++;
		}
		if (size > 1) {
			math(size, chars, &j);
		}
	}
	return j;
}
int main() {
	char a[] = { 'a','a','b','b','c','c','c' };
	compress(a, 7);

	return 0;
}