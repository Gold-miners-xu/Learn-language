#include<stdio.h>
int main() {
	int money = 20;//����$
	double drkmony = 1;//����
	int drink;
	int other = 2;//ÿƿ��Ҫ��ƿ
	double enddrkmon = drkmony - (drkmony - drkmony / other);//ʵ�ʵ���
	drink = money / enddrkmon;//ʵ�ʿ���
	printf("%d", drink);



	return 0;
}