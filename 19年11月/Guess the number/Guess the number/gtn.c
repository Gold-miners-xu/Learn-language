#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Interface() {
	printf("**********************\n");
	printf("********0.�˳�********\n");
	printf("********1.��ʼ********\n");
	printf("**********************\n");
}
int game() {
	int num = rand() % 100 + 1;
	int x;
	for (; 1 ;) {
		scanf("%d", &x);
		if (x > num)
			printf("����\n");
		else if (x < num)
			printf("С��\n");
		else {
			printf("���¶���\n");
			break;
		}
			
	}
}
int main() {
	srand((unsigned)time(NULL));
	int i;
	for (i = 1; i;) {
		Interface();
		scanf("%d", &i);
		if (i == 1)
			game();
		else if (i == 0)
			break;
		else
			printf("��������,����������\n");
	}

	return 0;
}