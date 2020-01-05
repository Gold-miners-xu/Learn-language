
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100    //��󶥵���
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 4


int degree[MAX];


//���������
typedef struct graph
{
	char ver[MAX];//������
	int vertex;    //��ǰ������
	int side;     //��ǰ����
	int arcs[MAX][MAX];//�ڽӾ���
}GRAPH, * pGRAPH;


//ջ�Ķ���
typedef struct SqStack
{
	int* base;    //ջ��ָ��
	int* top;
	int stacksize;   //��ǰ����Ĵ洢�ռ�
}SqStack;

//ջ�Ĵ���
void InitStack(SqStack* S)
{
	S->base = (int*)malloc(sizeof(int));
	if (S->base == NULL)
	{
		exit(-1);
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}

//�ж�ջ�Ƿ�Ϊ��

int StackEmpty(SqStack* S)
{
	if (S->top == S->base)
	{
		return 1;
	}
	else
		return 0;
}

//��ջ

void push(SqStack* S, int e)
{
	if (S->top - S->base >= S->stacksize)
	{
		S->base = (int*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(int));
		if (S->base == NULL)
			exit(-1);
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	S->top = e;
	S->top++;
}

//��ջ

int  pop(SqStack* S, int e)
{
	if (S->top = S->base)
	{
		return 0;
	}
	else {
		e = S->top;
		S->top--;
		return 1;
	}
}


//��������
void Finddegree(struct graph* G)
{
	for (int i = 0; i < G->vertex; i++)
	{
		for (int j = 0; j < G->vertex; j++)
		{
			if (G->arcs[j][i])
			{
				degree[i] = degree[i] + 1;
			}
		}
		printf("degree[%d]=%d\n", i, degree[i]);//���ж�������
	}
}

//��������
int TopSort(struct graph* G)
{
	int i, k;
	SqStack* S = NULL;

	int e = 0;
	int j = 0;

	InitStack(S);
	Finddegree(G);

	for (i = 0; i < G->vertex; i++)
	{
		if (!degree[i])
			push(S, i);
	}

	printf("��������\n");
	while (!StackEmpty(S))
	{
		pop(S, i);
		printf("%c\n", G->ver[i]);
		for (k = 0; k < G->vertex; k++)
		{
			if (G->arcs[i][k])
			{
				if (!(--degree[k]))
					push(S, k);
			}
		}
	}
	return 0;
}

//��������
void creat_graph(GRAPH* G)
{
	G->vertex = 6;
	G->side = 8;
	//������Ϣ
	for (int k = 0; k < 6; k++)
	{
		G->ver[k] = 'A' + k;
	}
	//��ʼ����ά����
	for (int i = 0; i < G->vertex; ++i)
	{
		for (int j = 0; j <= G->vertex; ++j)
		{
			G->arcs[i][j] = 0;
		}
	}
	G->arcs[0][1] = 3; G->arcs[0][2] = 2; G->arcs[1][4] = 3;
	G->arcs[2][3] = 4; G->arcs[1][3] = 2;
	G->arcs[2][5] = 3;
	G->arcs[3][5] = 2; G->arcs[4][5] = 1;
	//�������
	for (int h = 0; h < G->vertex; h++)
	{
		for (int j = 0; j < G->vertex; j++)
		{
			printf("%d  ", G->arcs[h][j]);
		}
		printf("\n");
	}
}

//��ؼ�·��

//void FineCriticalpath(GRAPH* G, SqStack* T)
//{
//	int* Ve;   //���緢��ʱ��
//	int* Vl;   //������ʱ��
//	int i;
//	int j;
//	int e;
//	int l;
//	char first;
//	char end;
//	int sum = 0;
//
//	SqStack* S = NULL;
//
//	Ve = (int*)malloc(sizeof(int) * G->side);
//	Vl = (int*)malloc(sizeof(int) * G->side);//��������������ʼ�ռ�
//
//	for (i = 0; i < G->side; i++)
//	{
//		Ve[i] = 0;
//		Vl[i] = 0;
//	}
//	//��ʼ����������
//
//	InitStack(S);
//	InitStack(T);
//	Finddegree(G);
//
//	for (i = 0; i < G->vertex; i++)
//	{
//		if (!degree[i])
//			push(S, i);
//	}
//	printf("����������������:\n");
//
//	while (!StackEmpty(S))
//	{
//		pop(S, i);
//
//		push(T, i);
//		printf("%c", G->ver[i]);
//		for (j = 0; j < G->vertex; j++)
//		{
//			if (G->arcs[i][j])
//			{
//				if (!(--degree[j]))
//					push(S, j);
//			}
//			if (Ve[i] + G->arcs[i][j] > Ve[j])     //���緢��ʱ�����
//			{
//				Ve[j] = Ve[i] + G->arcs[i][j];
//			}
//		}
//	}
//	//???????
//	for (i = 0; i < G->vertex; i++)
//	{
//		Vl[i] = Ve[G->vertex - 1];  //����ٷ���ʱ������鸽һ����ֵ
//	}
//
//	while (!StackEmpty(T))
//	{
//		pop(T, i);
//		for (j = 0; j <= G->vertex; j++)
//		{
//			if (G->arcs[i][j])
//			{
//				if (!(--degree[j]))
//					push(S, j);
//			}
//			if (Vl[j] - G->arcs[i][j] < Vl[i])     //��ٷ���ʱ�����
//			{
//				Vl[i] = Vl[j] - G->arcs[i][j];
//			}
//		}
//	}
//
//
//	for (i = 0; i < G->vertex; i++)
//		for (j = 0; j < G->side; j++)
//		{
//			e = Ve[i];
//			if (G->arcs[i][j])
//			{
//				l = Vl[j] - G->arcs[i][j];
//				printf("����%s �붥��%s  ������緢��ʱ��Ϊ%c  ���������ʱ��Ϊ%c\n", G->ver[i], G->ver[j], e, l);
//			}
//		}
//
//	printf("\n");
////	printf("�ù������Ϊ%c\n", first);
////	printf("�ù����յ�Ϊ%c\n", end);
//	printf("\n");
//
//	for (i = 0; i < G->vertex; j++)
//	{
//		for (j = 0; j < G->side; j++)
//		{
//			e = Ve[i];
//			if (G->arcs[i][j])
//			{
//				l = Vl[j] - G->arcs[i][j];
//				if (l == e)
//				{
//					printf("�ؼ��Ϊ%c\n", G->ver[i]);
//				}
//			}
//		}
//	}
//
//}




int main()
{
	SqStack* T = NULL;
	GRAPH* G = NULL;
	InitStack()
	creat_graph(G);
	TopSort(G);
//	FineCriticalpath(G, T);
	return 0;
}

