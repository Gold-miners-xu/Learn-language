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
	printf("�������¼�����(n)��");
	scanf("%d", &n);

	int* start = (int*)malloc(sizeof(int) * n);
	int* end = (int*)malloc(sizeof(int) * n);
	printf("������������¼��Ŀ�ʼ�ͽ���ʱ�䣺\n");
	for (int i = 0; i < n; i++)
		scanf("%d %d", &start[i], &end[i]);
	sort(start, n);
	sort(end, n);

	int j = 0;
	int sum = 0;	//�᳡����
	for (int i = 0; i < n; i++)
	{
		if (start[i] < end[j]) sum++; //���Ŀǰ���ʼʱ��С����һ�������ʱ��������һ���᳡ 
		else
			j++; //����͸û᳡�е���һ������ʱ����бȽ� 
	}
	printf("��Ҫ�᳡��%d", sum);
	return 0;
}
