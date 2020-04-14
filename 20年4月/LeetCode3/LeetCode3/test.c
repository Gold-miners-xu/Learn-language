#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int lengthOfLongestSubstring(char* s) {
	int len = strlen(s);
	int dic[256];
	for (int i = 0; i < 256; i++) {
		dic[i] = -1;
	}
	int max = 0;
	int left = 0;
	for (int i = 0; i < len; i++) {
		if (left <= dic[s[i]]) {
			left = dic[s[i]] + 1;

		}
		dic[s[i]] = i;
		if (i - left + 1 > max) {
			max = i - left + 1;
		}
	}
	return max;
}
int main() {
	char a[] = "aabaab!bb";
	lengthOfLongestSubstring(a);
	return 0;
}