#include<stdio.h>
#include<assert.h>
int Strcmp(const char* str1, const char* str2) {
	assert(str1 != NULL && str2 != NULL);
	while (*str1 != '\0' && *str2 != '\0'){
		if (*str1 < *str2)
			return -1;
		if (*str1 > *str2)
			return 1;
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0') {
		return 0;
	}
	else if (*str1 > * str2) {
		return 1;
	}
	return -1;
}

int main() {
	char a[] = "abn";
	char b[] = "abnc";
	printf("%d\n", Strcmp(a, b));
	return 0;
}