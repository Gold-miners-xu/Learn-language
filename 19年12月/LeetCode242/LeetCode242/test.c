#include<stdio.h>
#include<string.h>
char* sort(char* x) {
	for (int i = 0; i < strlen(x); i++) {
		for (int j = i + 1; j < strlen(x); j++) {
			if (x[i] > x[j]) {
				int tmp = x[i];
				x[i] = x[j];
				x[j] = tmp;
			}
		}
	}
	return x;
}//ð������(ʱ�临�Ӷȹ���,�ַ�������ʱ���ʺ�)
bool isAnagram(char* s, char* t)
{
	int i, x[26] = { 0 }, y[26] = { 0 };
	for (i = 0; s[i] != '\0'; i++)
		x[s[i] - 'a']++;
	for (i = 0; t[i] != '\0'; i++)
		y[t[i] - 'a']++;
	for (i = 0; i < 26; i++) {
		if (x[i] != y[i])
			return false;
	}
	return true;
}//��������,ʱ�临�Ӷ�С
int main() {
	char s[2] = "ab";
	char t[3] = "bae";
	char* a = s;
	char* b = t;
	sort(a);
	sort(b);
	return 0;
}
