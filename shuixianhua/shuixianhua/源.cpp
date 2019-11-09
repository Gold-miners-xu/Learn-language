#include<stdio.h>
#include<math.h>
int main() {
	int x, y, z;
	for (int i = 100; i < 1000; i++) {
		x = i % 10;
		y = (i / 10) % 10;
		z = i / 100;
		if (i == pow(x, 3) + pow(y, 3) + pow(z, 3))
			printf("%d\n", i);
	}
}