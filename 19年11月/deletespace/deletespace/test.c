#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int DeleteSpace(char str[],int i) {
	int space = 0;
	for (; str[space] == ' '; ) {
			space++;
	}
	int x;
	for ( x = space; str[x] != ' '; x++) {
		str[x - space] = str[x];
	}
	str[x - space] = '\0';
	for (int z = 0; z < i; z++) {
		if (str[z] == ' ') {
			str[z] = '\0';
			
		}
	}
	if (space > 0)
		return 1;
	return 0;
}
int main() {
	char str[100];
	gets(str);
	int x = strlen(str);
	for (; DeleteSpace(str, x);) {
		printf("%s\n", str);
		return 0;
	}
	printf("×Ö·û´®ÎÞspace\n");
	return 0;
}