#include<stdio.h>
#include<string.h>
char* addBinary(char* a, char* b) {
	int min, max;
	if (strlen(a) > strlen(b)) {
		max = strlen(a);
		min = strlen(b);
	}
	else {
		max = strlen(b);
		min = strlen(a);
	}
	int x = strlen(a) - 1;
	int y = strlen(b) - 1;
	char* ret = (char*)malloc(sizeof(char) * (max + 2));
	ret[max + 1] = '\0';
	int cont = 0;
	for (int i = max; i > 0; i--) {
		if (x >= 0 && y >= 0) {
			if (a[x] - '0' + b[y] - '0' + cont <= 1) {
				ret[i] = a[x] + b[y] + cont - '0';
				cont = 0;
			}
			else {
				ret[i] = a[x] + b[y] + cont - '0' - 2;
				cont = 1;
			}
		}
		else if (x >= 0) {
			if (cont == 1 && a[x] == '1') {
				ret[i] = '0';
			}
			else {
				ret[i] = a[x] + cont;
				cont = 0;
			}
		}
		else if (y >= 0) {
			if (cont == 1 && b[y] == '1') {
				ret[i] = '0';
			}
			else {
				ret[i] = b[y] + cont;
				cont = 0;
			}
		}
		x--;
		y--;
	}
	if (cont == 1) {
		ret[0] = '1';
		return ret;
	}
	else
		return ret + 1;
}
int main() {
	char a[] = "1";
	char b[] = "11";
	addBinary(a, b);
	return 0;
}