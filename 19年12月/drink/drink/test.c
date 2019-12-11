#include<stdio.h>
int main() {
	int money = 20;//可用$
	double drkmony = 1;//单价
	int drink;
	int other = 2;//每瓶需要空瓶
	double enddrkmon = drkmony - (drkmony - drkmony / other);//实际单价
	drink = money / enddrkmon;//实际可有
	printf("%d", drink);



	return 0;
}