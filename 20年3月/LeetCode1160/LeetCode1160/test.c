#include<stdio.h>
int countCharacters(char** words, int wordsSize, char* chars) {
	int rit = 0;

	for (int j = 0; j < wordsSize; j++) {
		int a[26] = { 0 };
		for (int i = 0; i < strlen(chars); i++) {
			a[chars[i] - 'a']++;
		}
		for (int k = 0; k < strlen(words[j]); k++) {
			if (a[words[j][k] - 'a'] > 0) {
				a[words[j][k] - 'a']--;
			}
			else {
				break;
			}
			if (k == strlen(words[j]) - 1) {
				rit += strlen(words[j]);
			}
		}

	}
	return rit;
}
int main() {

	return 0;
}