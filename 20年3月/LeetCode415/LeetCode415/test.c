#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* addStrings(char* num1, char* num2) {
	int str1 = strlen(num1);
	int str2 = strlen(num2);
	char* rit = (char*)malloc(sizeof(char) * (5200));
	int carry = 0;
	int k = 0;
	int i = str1 - 1, j = str2 - 1;
	while (i >= 0 || j >= 0 || carry != 0) {
		if (i >= 0) {
			carry += num1[i] - '0';
		}
		if (j >= 0) {
			carry += num2[j] - '0';
		}
		rit[k] = carry % 10 + '0';
		carry /= 10;
		k++;
		i--;
		j--;
	}
	rit[k] = '\0';
	i = 0;
	j = k - 1;
	while (i < j) {
		char tmp = rit[i];
		rit[i] = rit[j];
		rit[j] = tmp;
		i++;
		j--;
	}
	return rit;
}
int main() {
	char a[] = "131616315";
	char b[] = "515646";
	char* c = addStrings(a, b);
	printf("%s", c);
	return 0;
}