#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int pin = 987654;
	int key;
	printf("����������\n");
	for (int i = 0; i < 3; i++) {
		
		scanf("%d", &key);
		if (key == pin) {
			printf("������ȷ\n");
			break;
		}
		else if (i == 2) {
			printf("�������,���򼴽��˳�\n");
			break;
		}
		else {
			printf("�������,������\n");
		}
	}
	return 0;
}