#include<stdio.h>
#include<string.h>
int balancedStringSplit(char* s) {
	int sum = 0;
	int x = 0;
	char S;
	for (int i = 0; i < strlen(s); i++) {
		if (x == 0) {
			S = s[i];
			sum++;
		}
		if (S == s[i]) {
			x++;
		}
		if (S != s[i]) {
			x--;
		}

	}
	return sum;
}
int main() {
	char s[] = "rllrllrrrrrlll";
	balancedStringSplit(s);
	return 0;
}