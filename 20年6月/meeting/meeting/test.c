#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void sort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int main()
{
	int n;
	printf("请输入事件个数(n)：");
	scanf("%d", &n);

	int* start = (int*)malloc(sizeof(int) * n);
	int* end = (int*)malloc(sizeof(int) * n);
	printf("请依次输入各事件的开始和结束时间：\n");
	for (int i = 0; i < n; i++)
		scanf("%d %d", &start[i], &end[i]);
	sort(start, n);
	sort(end, n);

	int j = 0;
	int sum = 0;	//会场个数
	for (int i = 0; i < n; i++)
	{
		if (start[i] < end[j]) sum++; //如果目前活动开始时间小于上一个活动结束时间则另开辟一个会场 
		else
			j++; //否则和该会场中的下一个结束时间进行比较 
	}
	printf("需要会场：%d", sum);
	return 0;
}
