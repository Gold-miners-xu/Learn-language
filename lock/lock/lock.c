#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int pin = 987654;
	int key;
	printf("请输入密码\n");
	for (int i = 0; i < 3; i++) {
		
		scanf("%d", &key);
		if (key == pin) {
			printf("输入正确\n");
			break;
		}
		else if (i == 2) {
			printf("输入错误,程序即将退出\n");
			break;
		}
		else {
			printf("输入错误,请重试\n");
		}
	}
	return 0;
}