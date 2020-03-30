#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int* constructRectangle(int area, int* returnSize) {
	*returnSize = 2;
	int* a = (int*)calloc(2, sizeof(int));
	int i = (int)sqrt(area);
	//printf("%d",i);
	while (area % i != 0) {
		i--;
	}
	a[1] = i;
	a[0] = area / i;
	return a;
}
int main() {
	int b;
	int* a = constructRectangle(1, &b);
		printf("%d", a[1]);
	return 0;
}