#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int binary(int i[10],int num,int x,int y) {
	for (; 1;) {
		if (num == i[(x + y) / 2])
			return (x + y) / 2;
		else if (num < i[(x + y) / 2])
			y = (x + y) / 2 - 1;
		else if (num > i[(x + y) / 2])
			x = (x + y) / 2 + 1;
	}
	return -1;
}
int main() {
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	int num;
	scanf("%d", &num);
	int size = sizeof(a) / sizeof(a[0])-1;
	printf("Ë÷ÒýÊÇ%d", binary(a, num, 0, size));
	return 0;

	
}