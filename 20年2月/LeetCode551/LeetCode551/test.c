#include<stdio.h>
#include<string.h>
bool checkRecord(char* s) {
	int abs = 0;
	int late = 0;
	int i = 0;
	while (i < strlen(s)) {
		if (s[i] == 'A') {
			abs++;
			late = 0;
		}
		else if (s[i] == 'L') {
			late++;
		}
		else {
			late = 0;
		}
		if (abs > 1 || late > 2) {
			return false;
		}
		i++;
	}
	return true;
}
int main() {
	return 0;
}