#include<stdio.h>
#include<string.h>
int canConstruct(char* ransomNote, char* magazine) {

	int a[26] = { 0 };
	int num;
	for (int i = 0; i < strlen(magazine); i++) {
		num = magazine[i] - 'a';
		a[num]++;
	}
	for (int j = 0; j < strlen(ransomNote); j++) {
		num = ransomNote[j] - 'a';
		
		if (a[num] <= 0)
			return 0;
		a[num]--;
	}
	return 1;
}
int main() {
	char a[] = "aa";
	char b[] = "ab";
	canConstruct(a, b);
	return 0;
}