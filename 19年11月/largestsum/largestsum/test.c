#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int Largestsum(int a[],int len) {
	int sum = 0,maxsum = 0;
	for (int i = 0; i < len; i++) {
		sum += a[i];
		if (sum > maxsum)
			maxsum = sum;
		if (sum < 0)
			sum = 0;
	}
	return maxsum;
}//��������к�
int main() {
	int len;
	int a[100];
	printf("���������鳤��(С��100)\n");
	scanf("%d", &len);
	printf("����������Ԫ��\n");
	for (int i = 0; i < len; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d", Largestsum(a,len));
	return 0;
}