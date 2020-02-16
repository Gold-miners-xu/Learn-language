#include<stdio.h>
#include<string.h>
bool oneEditAway(char* first, char* second) {
	int strf = strlen(first);
	int strs = strlen(second);
	if (strf == strs) {
		int num = 0, i = 0;
		while (i < strs) {
			if (first[i] != second[i]) {
				num++;
			}
			if (num > 1) {
				return false;
			}
			i++;
		}
		return true;
	}
	else if (strs + 1 == strf) {
		int i = 0, j = 0;
		while (i < strf) {
			if (first[i] != second[j]) {
				i++;
			}
			else {
				j++;
				i++;
			}
			if (i > j + 1) {
				return false;
			}

		}
		return true;
	}
	else if (strf + 1 == strs) {
		int i = 0, j = 0;
		while (i < strs) {
			if (first[j] != second[i]) {
				i++;
			}
			else {
				j++;
				i++;
			}
			if (i > j + 1) {
				return false;
			}

		}
		return true;
	}
	else
		return false;

}
int main() {
	return 0;
}