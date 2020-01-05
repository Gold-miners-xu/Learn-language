
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100    //最大顶点数
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 4


int degree[MAX];


//矩阵的声明
typedef struct graph
{
	char ver[MAX];//顶点数
	int vertex;    //当前顶点数
	int side;     //当前边数
	int arcs[MAX][MAX];//邻接矩阵
}GRAPH, * pGRAPH;


//栈的定义
typedef struct SqStack
{
	int* base;    //栈底指针
	int* top;
	int stacksize;   //当前分配的存储空间
}SqStack;

//栈的创建
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

//判断栈是否为空

int StackEmpty(SqStack* S)
{
	if (S->top == S->base)
	{
		return 1;
	}
	else
		return 0;
}

//进栈

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

//出栈

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


//顶点的入度
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
		printf("degree[%d]=%d\n", i, degree[i]);//所有定点的入度
	}
}

//拓扑排序
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

	printf("拓扑排序\n");
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

//创建矩阵
void creat_graph(GRAPH* G)
{
	G->vertex = 6;
	G->side = 8;
	//顶点信息
	for (int k = 0; k < 6; k++)
	{
		G->ver[k] = 'A' + k;
	}
	//初始化二维数组
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
	//输出矩阵
	for (int h = 0; h < G->vertex; h++)
	{
		for (int j = 0; j < G->vertex; j++)
		{
			printf("%d  ", G->arcs[h][j]);
		}
		printf("\n");
	}
}

//求关键路径

//void FineCriticalpath(GRAPH* G, SqStack* T)
//{
//	int* Ve;   //最早发生时间
//	int* Vl;   //最晚发生时间
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
//	Vl = (int*)malloc(sizeof(int) * G->side);//给两个数组分配初始空间
//
//	for (i = 0; i < G->side; i++)
//	{
//		Ve[i] = 0;
//		Vl[i] = 0;
//	}
//	//初始化两个数组
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
//	printf("拓扑排序序列如下:\n");
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
//			if (Ve[i] + G->arcs[i][j] > Ve[j])     //最早发生时间计算
//			{
//				Ve[j] = Ve[i] + G->arcs[i][j];
//			}
//		}
//	}
//	//???????
//	for (i = 0; i < G->vertex; i++)
//	{
//		Vl[i] = Ve[G->vertex - 1];  //给最迟发生时间的数组附一个大值
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
//			if (Vl[j] - G->arcs[i][j] < Vl[i])     //最迟发生时间计算
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
//				printf("顶点%s 与顶点%s  活动的最早发生时间为%c  活动的最晚发生时间为%c\n", G->ver[i], G->ver[j], e, l);
//			}
//		}
//
//	printf("\n");
////	printf("该工程起点为%c\n", first);
////	printf("该工程终点为%c\n", end);
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
//					printf("关键活动为%c\n", G->ver[i]);
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

