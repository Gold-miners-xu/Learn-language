#include<stdio.h>
char nextGreatestLetter(char* letters, int lettersSize, char target) {
	char ret = letters[0];
	for (int i = 0; i < lettersSize; i++) {
		if (letters[i] > target) {
			return letters[i];
		}
	}
	return ret;
}
int main() {
	return 0;
}