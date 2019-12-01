#include<stdio.h>
void D10p2(int a[4]) {
	for (int i = 0; i < 4; i++) {
		a[i] = 1;
		if ((a[0] != 1) + (a[2] == 1) + (a[3] == 1) + (a[3] != 1) == 3)
			printf("%cÊÇÐ×ÊÖ", 'A' + i);
		a[i] = 0;
	}
}
int main() {
	int a[4] = { 0 };
	D10p2(a);
	return 0;
}