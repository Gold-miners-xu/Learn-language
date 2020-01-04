#include<stdio.h>
void reverseString(char* s, int sSize) {
	if (sSize <= 1) {
		return;
	}
	int end = sSize - 1;
	for (int i = 0; i < end; i++, end--) {
		char tmp = s[i];
		s[i] = s[end];
		s[end] = tmp;
	}
}//·´×ª×Ö·û´®
int main() {
	return 0;
}