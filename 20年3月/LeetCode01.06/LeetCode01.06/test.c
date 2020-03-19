#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void mrfc(int x, char* s, int* a) {
	if (x > 9) {
		mrfc(x / 10, s, a);
	}
	s[*a] = '0' + x % 10;
	(*a)++;
}
char* compressString(char* S) {
	char* rit = (char*)malloc(sizeof(char) * strlen(S + 1));
	int num = 0;
	int j = 0;
	char s = S[0];
	printf("%d", strlen(S));
	for (int i = 0; i < strlen(S); i++) {
		if (S[i + 1] == '\0') {
			rit[j] = s;
			j++;
			mrfc(++num, rit, &j);
		}
		if (s != S[i]) {
			rit[j] = s;
			j++;
			mrfc(num, rit, &j);
			s = S[i];
			num = 0;
		}
		num++;
	}
	rit[j] = '\0';
	return rit;
}
int main() {
	char S[] = "abbccd";
	compressString(S);
	return 0;

}
