#include<stdio.h>
#include<assert.h>
char* Strcat(char* dest, const char* src) {
	if (dest == NULL || src == NULL) {
		return dest;
	}
	char* rit = dest;
	while (*dest != '\0') {
		assert(dest != NULL);
		dest++;
	}
	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return rit;

}
int main() {
	char a[50] = "I like ";
	char b[] = "apple";
	printf("%s\n", Strcat(a, b));
	return 0;
}