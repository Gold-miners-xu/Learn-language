#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool isValid(char* s) {
	int len = strlen(s);
	if (len % 2 != 0) {
		return false;
	}
	char* str = malloc(sizeof(char) * len);
	int lens = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			str[lens] = s[i];
			lens++;
		}
		else if (lens == 0) {
			return false;
		}
		else if (s[i] == ')') {
			if (str[lens - 1] != '(') {
				return false;
			}
			else {
				lens--;
			}
		}
		else if (s[i] == ']') {
			if (str[lens - 1] != '[') {
				return false;
			}
			else {
				lens--;
			}
		}
		else if (s[i] == '}') {
			if (str[lens - 1] != '{') {
				return false;
			}
			else {
				lens--;
			}
		}

	}
	if (lens == 0) {
		return true;
	}
	return false;
}
int main() {
	return 0;
}