#include<stdio.h>
//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf(" % d % d", a + b, c);
//	return 0;
//}

//int main()
//{
//	char a[1000] = { 0 };
//	int i = 0;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d", strlen(a));
//	return 0;
//}
void Print(long long i) {
	if (i > 9) {
		Print(i / 10);
		i %= 10;
	}
	printf("%d", i);
}
int main() {
	long long x = 1;
	printf("1\n");
	for (int i = 1; i < 10; i++) {
		int j = 0;
		x *= 11;	
		Print(x);
		printf("\n");
	}
	return 0;
}