#include <stdio.h>
#include<stdlib.h>

int Max(int x, int y){
	int z;
	z = x > y ? x : y;
	return z;
}
int Min(int x, int y) {
	int z;
	z = x > y ? y : x;
	return z;
}
int main() {
	
	int (*p)(int x, int y) = &Max;
	int a = 0, b = 0, c = 0, d = 0;
	printf_s("Pliease inter two number :\n");
	printf("ÇëÊäÈëÊı×Ö");
	scanf_s("%d", &c);
	d = (*p)(a, b);
	if (c == 1) {
		p = &Max;
	}
	else if (c == 2) {
		p = &Min;
	}
	d = (*p)(a, b);
	printf_s("d=%d\n", d);
	system("pause");
	return 0;
}

