#include<stdio.h>
#include<string.h>
int numJewelsInStones(char* J, char* S) {
	int count = 0;
	for (int i = 0; i < strlen(S); i++) {
		for (int j = 0; j < strlen(J); j++) {
			if (S[i] == J[j])
				count++;
		}
	}
	return count;
}
int main() {

	return 0;
}