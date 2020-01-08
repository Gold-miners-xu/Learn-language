#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <malloc.h>
#include<cstdlib>
#include <string.h>

// 图的邻接表存储表示 p163
//#define  MAX_NAME 3					// 顶点字符串的最大长度+1 
#define MAX_VERTEX_NUM 20           //最大顶点数
typedef int InfoType;				// 权值为int型
typedef char VertexType[3];	// 顶点字符串类型 




// 表结点 
typedef struct ArcNode
{
	int adjvex;					// 该弧所指向的顶点的位置    弧头指向的顶点在数组中的下标
	struct ArcNode* nextarc;	// 指向下一条弧头的指针 
	int* info;				// 权值指针
}ArcNode;


//头结点
typedef struct VNode
{
	VertexType data;			// 顶点内容 
	ArcNode* firstarc;			//指向第一个邻接点的指针
}VNode, AdjList[MAX_VERTEX_NUM];// 存储链表头节点数组





typedef struct
{
	AdjList vertices;//图中顶点的数组
	int vexnum, arcnum;	// 顶点数和弧数
}ALGraph;

int ve[MAX_VERTEX_NUM]; // 全局变量

// 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1。 
int LocateVex(ALGraph G, VertexType u)
{
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (strcmp(u, G.vertices[i].data) == 0)
			return i;
	return -1;
}



int CreateGraph(ALGraph* G)//创建邻接表
{
	int i, j, k;
	int w;	//权值
	ArcNode* p;
	VertexType va, vb;
	printf("请输入顶点和边的数目: \n");
	scanf("%d%d", &(*G).vexnum, &(*G).arcnum);
	printf("请输入各顶点值: \n", (*G).vexnum, 3);
	for (i = 0; i < (*G).vexnum; ++i) {
		scanf("%s", &(*G).vertices[i].data);
		(*G).vertices[i].firstarc = NULL;
	}
	printf("请输入每条边的权值和弧尾和弧头:\n");
	for (k = 0; k < (*G).arcnum; ++k) {
		scanf("%d%s%s", &w, va, vb);
		i = LocateVex(*G, va); j = LocateVex(*G, vb);//定位
		p = (ArcNode*)malloc(sizeof(ArcNode));//申请一个结点
		p->adjvex = j;
		p->info = (int*)malloc(sizeof(int));
		*(p->info) = w;//赋值
		p->nextarc = (*G).vertices[i].firstarc;//连接结点
		(*G).vertices[i].firstarc = p;
	}
	return 1;
}

void print(ALGraph G)
{
	int i;
	ArcNode* p;
	printf("%d个顶点：\n", G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
		printf("%s ", G.vertices[i].data);
	printf("\n%d条弧(边):\n", G.arcnum);
	for (i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			printf("%s→%s ", G.vertices[i].data,
				G.vertices[p->adjvex].data);
			printf(":%d ", *(p->info));
			p = p->nextarc;
		}
		printf("\n");
	}
}


typedef int SElemType; // 栈类型
#define STACK_INIT_SIZE 10	// 存储空间初始分配量 
#define STACKINCREMENT 2	// 存储空间分配增量 
typedef struct SqStack
{
	SElemType* base;	// 在栈构造之前和销毁之后，base的值为NULL 
	SElemType* top;		// 栈顶指针 
	int stacksize;		// 当前已分配的存储空间，以元素为单位 
}SqStack;	// 顺序栈

int InitStack(SqStack* S)//	构造一个空栈S。
{
	// 为栈底分配一个指定大小的存储空间
	(*S).base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!(*S).base)
		exit(0);		// 存储分配失败 
	(*S).top = (*S).base;	// 栈空
	(*S).stacksize = STACK_INIT_SIZE;
	return 1;
}

int StackEmpty(SqStack S)// 若栈空，则返回1，否则返回0
{
	if (S.top == S.base)
		return 1;
	else
		return 0;
}

int Push(SqStack* S, SElemType e)//	插入元素e为新的栈顶元素。
{
	if ((*S).top - (*S).base >= (*S).stacksize)	// 栈满，追加存储空间 
	{
		(*S).base = (SElemType*)realloc((*S).base,
			((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!(*S).base)
			exit(0); // 存储分配失败 
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++ = e;

	return 1;
}



int Pop(SqStack* S, SElemType* e)//	若栈不空，则删除S的栈顶元素，用e返回其值，并返回1；否则返回0。
{
	if ((*S).top == (*S).base)
		return 0;
	*e = *--(*S).top;
	return 1;
}


void findindegree(ALGraph G, int indegree[])//求顶点的入度
{
	int i;
	ArcNode* p;
	for (i = 0; i < G.vexnum; i++)
		indegree[i] = 0;
	for (i = 0; i < G.vexnum; i++) {
		p = G.vertices[i].firstarc;
		while (p) {
			indegree[p->adjvex]++;
			p = p->nextarc;
		}
		printf("\n");
	}
}

int Topolog(ALGraph G, SqStack* T)
{
	int j, k, count, indegree[MAX_VERTEX_NUM];
	SqStack S;
	ArcNode* p;
	findindegree(G, indegree);//求各顶点入度
	InitStack(&S);
	for (j = 0; j < G.vexnum; j++)
		if (!indegree[j])
			Push(&S, j);//度为0入栈
	InitStack(T);
	count = 0;//对输出顶点记数
	for (j = 0; j < G.vexnum; ++j)
		ve[j] = 0;
	while (!StackEmpty(S)) {
		Pop(&S, &j);
		Push(T, j);
		++count;
		for (p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			if (--indegree[k] == 0)  Push(&S, k);
			if (ve[j] + *(p->info) > ve[k])
				ve[k] = ve[j] + *(p->info);//最早发生时间ve
		}
	}
	if (count < G.vexnum)
	{
		printf("此有向图有回路\n");
		return 0;
	}
	else return 1;
}
//关键活动
int activity(ALGraph G)
{
	int vl[MAX_VERTEX_NUM];
	SqStack T;
	int i, j, k, ee, el;
	ArcNode* p;
	char dut, tag;

	if (!Topolog(G, &T)) // 产生有向环 
		return 0;
	j = ve[0];
	for (i = 1; i < G.vexnum; i++) // j=Max(ve[]) 完成点的值 
		if (ve[i] > j)
			j = ve[i];
	for (i = 0; i < G.vexnum; i++) // 初始化顶点事件的最迟发生时间(最大值) 
		vl[i] = j; // 完成点的最早发生时间 
	while (!StackEmpty(T)) // 按拓扑逆序求各顶点的vl值 
		for (Pop(&T, &j), p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			dut = *(p->info); // dut<j,k>
			if (vl[k] - dut < vl[j])
				vl[j] = vl[k] - dut;//最迟发生时间
		}
	printf(" j  k  dut  ee  el  tag\n");
	for (j = 0; j < G.vexnum; ++j) // 求ee,el和关键活动 
		for (p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			dut = *(p->info);
			ee = ve[j];
			el = vl[k] - dut;
			tag = (ee == el) ? '*' : ' ';
			// 输出关键活动
			printf("%2d %2d %3d %3d %3d    %c\n", j, k, dut, ee, el, tag);
		}
	printf("关键活动为:\n");
	for (j = 0; j < G.vexnum; ++j) // 同上 
		for (p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			dut = *(p->info);
			if (ve[j] == vl[k] - dut)
				// 输出关键活动 
				printf("%s→%s\n", G.vertices[j].data, G.vertices[k].data);
		}
	return 1;
}
int main()
{
	ALGraph h;
	CreateGraph(&h);
	print(h);
	activity(h);
	return 0;
}