#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	char cvn;
	for (int i = 1; i;) {
		printf("������һ����ĸ\n");
		scanf("%c", &cvn);
		if (cvn > 64 && cvn < 91) {
			printf("%c\n", cvn + 32);
			break;
		}
			
		else if (cvn > 96 && cvn < 123) {
			printf("%c\n", cvn - 32);
			break;
		}
		    
		else {
			printf("��������,���������������»�����0�˳�\n");
			scanf("%d", &i);
		}
	}
	return 0;
}