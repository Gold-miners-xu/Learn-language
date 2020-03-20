#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int longestPalindrome(char* s) {
	int str = strlen(s);
	int odd = 0, rit = 0;
	int* alp = (int*)calloc(52, sizeof(int));
	for (int i = 0; i < str; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			alp[s[i] - 'a']++;
		}
		else {
			alp[s[i] - 'A' + 26]++;
		}
	}
	for (int j = 0; j < 52; j++) {
		if (alp[j] % 2 == 0) {
			rit += alp[j];
		}
		else {
			odd++;
			rit += alp[j] - 1;
		}
	}
	if (odd > 0) {
		rit++;
	}
	return rit;
}
int main() {

	return 0;
}