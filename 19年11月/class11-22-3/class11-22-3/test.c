#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void recursive(int n) {
	if (n > 9)
		recursive(n / 10);//���ϵ�������
	printf("%d ",n % 10);
}//�ݹ��ӡÿһλ��
int main() {
	int x;
	scanf("%d", &x);
	recursive(x);
	return 0;
}