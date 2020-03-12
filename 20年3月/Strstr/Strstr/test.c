#include<stdio.h>
#include<string.h>
#include<assert.h>
const char* Strstr(const char* str1, const char* str2) {
	assert(str1 != NULL || str2 != NULL);
	if (*str2 == '\0') {
		return NULL;
	}
	int num = strlen(str2);
	char* rit = str1;
	char* rit2 = str2;
	while (*rit != '\0') {
		while (*rit != '\0' && *rit2 != '\0' && (*rit == *rit2)){
			rit++;
			rit2++;
		}
		if (*rit2 == '\0') {
			return rit - num;
		}
		if (*rit == '\0') {
			return NULL;
		}

		rit++;
	}
	return NULL;
}
int main() {
	char a[] = "what fake";
	char b[] = "what";
	char* x = Strstr(a, b);
	if (a == x) {
		printf("yes");
	}
	return 0;
}
