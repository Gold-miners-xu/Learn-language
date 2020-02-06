#include<stdio.h>
#include<string.h>
char findTheDifference(char* s, char* t) {
	char a = t[strlen(s)];
	for (int i = 0; i < strlen(s); i++) {
		a ^= s[i];
		a ^= t[i];
	}
	return a;
}
int main() {
	return 0;
}