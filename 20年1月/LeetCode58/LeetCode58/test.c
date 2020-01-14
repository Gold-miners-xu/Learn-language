#include<stdio.h>
#include<string.h>
int lengthOfLastWord(char* s) {
	int rit = 0;
	for (int i = strlen(s) - 1; i >= 0; i--) {
		if (s[i] != ' ') {
			rit++;
		}
		else if (rit != 0) {
			break;
		}
	}
	printf("%d", rit);
	return rit;
}
int main() {
	char a[] = "a";
	lengthOfLastWord(&a);
	return 0;
}