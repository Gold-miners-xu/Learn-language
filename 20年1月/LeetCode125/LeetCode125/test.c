#include<stdio.h>
#include<string.h>
bool isPalindrome(char* s) {
	if (strlen(s) == 0) {
		return true;
	}
	int left = 0, rit = strlen(s) - 1;
	while (left < rit) {
		while (1) {
			if (s[left] >= '0' && s[left] <= '9') {
				break;
			}
			else if (s[left] >= 'A' && s[left] <= 'Z') {
				break;
			}
			else if (s[left] >= 'a' && s[left] <= 'z') {
				s[left] -= 32;
				break;
			}
			else {
				left++;
			}
			if (left > strlen(s))
				return true;
		}
		while (1) {
			if (s[rit] >= '0' && s[rit] <= '9') {
				break;
			}
			else if (s[rit] >= 'A' && s[rit] <= 'Z') {
				break;
			}
			else if (s[rit] >= 'a' && s[rit] <= 'z') {
				s[rit] -= 32;
				break;
			}
			else {
				rit--;
			}
			if (rit < 0)
				return true;
		}
		if (s[left] != s[rit]) {
			return false;
		}

		left++;
		rit--;
	}
	return true;
}
int main() {
	char a[] = "race a car";
	isPalindrome(a);
	return 0;
}