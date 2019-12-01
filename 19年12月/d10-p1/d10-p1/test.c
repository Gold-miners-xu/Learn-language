#include<stdio.h>
int Isrepeat(int a, int b, int c, int d, int e) {
	int tmp = 0;
	tmp |= 1 << (a - 1);
	tmp |= 1 << (b - 1);
	tmp |= 1 << (c - 1);
	tmp |= 1 << (d - 1);
	tmp |= 1 << (e - 1);
	if (tmp == 31)
		return 1;
	return 0;
}
void D10p1(int x[5]) {
	for (int a = 1; a < 6; a++) {
		for (int b = 1; b < 6; b++) {
			for (int c = 1; c < 6; c++) {
				for (int d = 1; d < 6; d++) {
					for (int e = 1; e < 6; e++) {
						if ((b == 2) + (a == 3) == 1 &&
							(b == 2) + (e == 4) == 1 &&
							(c == 1) + (d == 2) == 1 &&
							(c == 5) + (d == 3) == 1 &&
							(e == 4) + (a == 1) == 1&&
							Isrepeat(a,b,c,d,e)
							)
							printf("a第%d,b第%d,c第%d,d第%d,e第%d", a, b, c, d, e);
					}
				}
			}
		}
	}
}
int main() {
	int a[5] = { 0 };
	D10p1(a);
	return 0;
}