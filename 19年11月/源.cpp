#include <stdio.h>
void sheet(int n) {
	int x, y;
	for (x = 1; x <= n; x++) {
		for (y = 1; y <= x; y++) {
			printf("%d*%d=%d ", y, x x * y);
		}
		printf("\n");
	}
}
int main()
{
	int i = 0;
	scanf("%d", &i);
	sheet(i);
	
    return 0;
}
