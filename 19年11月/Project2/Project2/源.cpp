#include<stdio.h>
int main() {
	for (int i = 100,k = 0; i <= 200; i++) {
		for (int j = 2; j < i; j++) {
			if (i % j == 0)
				break;
			else if (i == j + 1) {
				printf("%d\t", i);
				k++;
				if (k % 5 == 0)
		        printf("\n");
			}
		}
		
	}
	
	return 0;
}