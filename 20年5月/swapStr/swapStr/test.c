#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char* s, int i, int j) {
	char a = s[i];
	s[i] = s[j];
	s[j] = a;
}
char* reverseVowels(char* s) {
	int rit = strlen(s) - 1;
	int left = 0;

	while (rit > left) {
		while (rit > left && s[rit] != 'A' && s[rit] != 'E' && s[rit] != 'I' && s[rit] != 'O' && s[rit] != 'U' && s[rit] != 'a' && s[rit] != 'e' && s[rit] != 'i' && s[rit] != 'o'
			&& s[rit] != 'u') {
			rit--;
		}
		while (rit > left && s[left] != 'A' && s[left] != 'E' && s[left] != 'I' && s[left] != 'O' && s[left] != 'U' && s[left] != 'a' && s[left] != 'e' && s[left] != 'i' && s[left] != 'o' && s[left] != 'u') {
			left++;
		}
		if (left >= rit)
			continue;
		swap(s, rit, left);
		rit--;
		left++;
	}
	return s;
}
int main() {
	char s[] = "Red Roses run no risk, sir, on nurses order.";
	reverseVowels(s);
	return 0;
}