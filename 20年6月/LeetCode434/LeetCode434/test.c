#include<stdio.h>
int countSegments(char* s) {
	int res = 0;
	int count = 0;
	while (*s != '\0') {
		if (count == 0 && *s != ' ') {
			count = 1;
			res++;
		}
		else if (count == 1 && *s == ' ') {
			count = 0;
		}

		s++;
	}
	return res;
}