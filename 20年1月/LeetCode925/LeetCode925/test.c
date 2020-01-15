#include<stdio.h>
#include<string.h>
bool isLongPressedName(char* name, char* typed) {
	int j = 0;
	int rit = 0;
	for (int i = 0; i < strlen(name); i++) {

		for (; j < strlen(typed); j++) {
			if (typed[j] == name[i]) {
				rit++;
				j++;
				break;
			}
		}

	}
	if (rit == strlen(name))
		return true;
	return false;
}
int main() {
	return 0;
}