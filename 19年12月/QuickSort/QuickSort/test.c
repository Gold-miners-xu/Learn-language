#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void QuickSort(int* a, int left, int rit) {

	if (left > rit)
		return;
	int tmp;
	int i = left, j = rit;
	for (; i < j;) {
		while (i<j && a[i] <= a[j]) {
			j--;
		}
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;

		for (; i < j && a[i] <= a[j];) {
			i++;
		}
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	QuickSort(a, left, i - 1);
	QuickSort(a, i + 1, rit);

}
int main() {
	int a[10];
	printf("请输入待排序的十个数\n");
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	QuickSort(a, 0, 9);
	for (int j = 0; j < 10; j++) {
		printf("%d\n", a[j]);
	}
	return 0;
}
/*
一个表达式对一个值进行多次修改,最终结果无法确定,(未定义行为)
内存的特点:
1.内存支持随机访问.CPU访问内存时,访问任何一个地址的代价非常低,]
2.内存和外存对比(硬盘,软盘...)
   1>访问速度:内存访问速度快(ns),访问外村速度慢(us)_(3-4个数量级)
   2>容量;内存容量小,外存容量大
   3>成本:内存成本高,外存成本低
   4>断电:内存断电后数据丢失,外存断电,数据依然存在
内存必须申请之后才能使用,没申请不能使用,,强行使用为申请内存,就会出现访问非法内存,
是一种未定义行为.(非常危险的一种操作)
包含非法地址的指针,叫"野指针",对野指针解引用非常危险.
   有一种特殊的指针,只有地址,没有内存大小,void*,void*对应的内存大小可以是任意大小,
但不能解引用,当函数不需要关注类型,或者需要支持多种指针类型时,可以用void*(memset)
   空指针:空指针地址为0,特殊的一种野指针,

   不同系统上,类型长度不同
   指针为初始化,默认随机位置,



*/