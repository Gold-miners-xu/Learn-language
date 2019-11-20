#include <stdio.h>
int main() {
	for (int i = 1; i <= 13; i++) {
		if (i <= 7)
			for (int j = 0; j < i * 2 - 1; j++) {
				printf("*");
			}
		else
			for (int y = 11; y > 2 * i - 16; y--) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}