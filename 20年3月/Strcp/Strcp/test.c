#include<stdio.h>
char* Strcpy(char* dest, const char* src) {
	if (dest == NULL || src == NULL) {
		return dest;
	}
	char* rit = dest;
	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return rit;
}
int Strlen(char* dest) {
	if (dest == NULL) {
		return -1;
	}
	int rit = 0;
	while (*dest != '\0') {
		dest++;
		rit++;
	}
	return rit;
}
int main() {
	char a[50];
	char b[] = "apple";
	//printf("%s\n", Strcpy(a, b));
	printf("%d\n", Strlen(b));
	return 0;
}