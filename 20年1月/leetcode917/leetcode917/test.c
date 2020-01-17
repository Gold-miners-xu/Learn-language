#include<stdio.h>
#include<string.h>
char* reverseOnlyLetters(char* S) {
	int left = 0;
	int rit = strlen(S) - 1;
	while (left < rit) {
		if ((S[left] < 'A' || S[left] > 'Z') && (S[left] < 'a' || S[left] > 'z')) {
			left++;
			continue;
		}
		if ((S[rit] < 'A' || S[rit] > 'Z') && (S[rit] < 'a' || S[rit] > 'z')) {
			rit--;
			continue;
		}
		int tmp = S[left];
		S[left] = S[rit];
		S[rit] = tmp;
		left++;
		rit--;
	}
	return S;
}
int main() {
	char s[] = "ab-cd";
	reverseOnlyLetters(s);
	return 0;
}