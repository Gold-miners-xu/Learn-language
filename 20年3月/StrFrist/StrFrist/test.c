#include<stdio.h>
#include<string.h>
int firstUniqChar(char* s) {
	int a[26] = { 0 };
	int slen = strlen(s);
	int x;
	for (int i = 0; i < slen; i++) {
		x = (int)s[i] - (int)'a';
		a[x]++;
	}
	for (int j = 0; j < slen; j++) {
		if (a[s[j] - 'a'] == 1) {
			return j;
		}
	}
	return -1;
}
int main() {


	return 0;
}