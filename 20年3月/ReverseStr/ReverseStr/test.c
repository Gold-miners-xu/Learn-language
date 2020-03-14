#include<stdio.h>
#include<string.h>
void reverse(char* s, int i, int j) {
	while (i < j) {
		char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}
char* reverseStr(char* s, int k) {
	int i = 0;
	int j = 0;
	while (i < strlen) {
		j = i + k - 1;
		if (j > strlen(s) - 1) {
			j = strlen(s) - 1;
		}
		reverse(s, i, j);
		i += (2 * k);
	}
	return s;
}
int main() {
	return 0;
}