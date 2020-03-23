#include<stdio.h>
#include<string.h>
char* Strncat(char* a, const char* b, unsigned int c) {
	char* rit = a;
	while (*a != '\0') {
		a++;
	}
	for (int i = 0; i < c; i++) {
		*a = *b;
		a++;
		b++;
	}
	*a = '\0';
	return rit;
}
int main() {
	char a[20] = "i love";
	char b[10] = "world";
	Strncat(a, b, 5);
	printf("%s", a);
	return 0;
}