#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int count(int num) {
	int count = 0;
	for (; num;) {
		if (num < 0) {
			count++;
		}
		
		num = num << 1;
	}
	return count;
}//��һ��ʮ������ת��Ϊ�����������ж���1
int count2() {
	int x;
	int a = 0;
	int b = 0;
	int c = 0;
	x = ++a || ++b || c++;
	printf("a = %d b = %d c = %d", a, b, c);
}//��·��ֵ
int main() 
{
	int x;
	scanf("%d", &x);
	printf("%d", count(x));
	return 0;
}
