

#include<stdio.h>
int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	int* p = a;
	printf("%d,", *p);//p->a[0]
	printf("%d,", *(++p));//p->a[1]
	printf("%d,", (*p)++);//a[1]=3
	printf("%d,", *p);
	printf("%d,", *p--);//p->a[0]
	printf("%d,", --(*p));//a[0]=0
	printf("%d \n", *p);//a[0]
	return 0;
	/*int a[3] = { 0,2,9 };
	int* p = a;
	printf("%d,%d\n", *p++, (*p)++);
	printf("%d,%d,%d", *p, *p++, (*p)++);
	return 0;*/
}