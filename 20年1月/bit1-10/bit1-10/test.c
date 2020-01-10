#include<stdio.h>
char* toLowerCase(char* str) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
	}
	return str;
}
int main() {
	int i = 2;
	int p = 4;
	p *= i + 3;
	printf("%d", p);
	return 0;
}