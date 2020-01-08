#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <malloc.h>
#include<cstdlib>
#include <string.h>

// ͼ���ڽӱ�洢��ʾ p163
//#define  MAX_NAME 3					// �����ַ�������󳤶�+1 
#define MAX_VERTEX_NUM 20           //��󶥵���
typedef int InfoType;				// ȨֵΪint��
typedef char VertexType[3];	// �����ַ������� 




// ���� 
typedef struct ArcNode
{
	int adjvex;					// �û���ָ��Ķ����λ��    ��ͷָ��Ķ����������е��±�
	struct ArcNode* nextarc;	// ָ����һ����ͷ��ָ�� 
	int* info;				// Ȩֵָ��
}ArcNode;


//ͷ���
typedef struct VNode
{
	VertexType data;			// �������� 
	ArcNode* firstarc;			//ָ���һ���ڽӵ��ָ��
}VNode, AdjList[MAX_VERTEX_NUM];// �洢����ͷ�ڵ�����





typedef struct
{
	AdjList vertices;//ͼ�ж��������
	int vexnum, arcnum;	// �������ͻ���
}ALGraph;

int ve[MAX_VERTEX_NUM]; // ȫ�ֱ���

// ��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1�� 
int LocateVex(ALGraph G, VertexType u)
{
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (strcmp(u, G.vertices[i].data) == 0)
			return i;
	return -1;
}



int CreateGraph(ALGraph* G)//�����ڽӱ�
{
	int i, j, k;
	int w;	//Ȩֵ
	ArcNode* p;
	VertexType va, vb;
	printf("�����붥��ͱߵ���Ŀ: \n");
	scanf("%d%d", &(*G).vexnum, &(*G).arcnum);
	printf("�����������ֵ: \n", (*G).vexnum, 3);
	for (i = 0; i < (*G).vexnum; ++i) {
		scanf("%s", &(*G).vertices[i].data);
		(*G).vertices[i].firstarc = NULL;
	}
	printf("������ÿ���ߵ�Ȩֵ�ͻ�β�ͻ�ͷ:\n");
	for (k = 0; k < (*G).arcnum; ++k) {
		scanf("%d%s%s", &w, va, vb);
		i = LocateVex(*G, va); j = LocateVex(*G, vb);//��λ
		p = (ArcNode*)malloc(sizeof(ArcNode));//����һ�����
		p->adjvex = j;
		p->info = (int*)malloc(sizeof(int));
		*(p->info) = w;//��ֵ
		p->nextarc = (*G).vertices[i].firstarc;//���ӽ��
		(*G).vertices[i].firstarc = p;
	}
	return 1;
}

void print(ALGraph G)
{
	int i;
	ArcNode* p;
	printf("%d�����㣺\n", G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
		printf("%s ", G.vertices[i].data);
	printf("\n%d����(��):\n", G.arcnum);
	for (i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			printf("%s��%s ", G.vertices[i].data,
				G.vertices[p->adjvex].data);
			printf(":%d ", *(p->info));
			p = p->nextarc;
		}
		printf("\n");
	}
}


typedef int SElemType; // ջ����
#define STACK_INIT_SIZE 10	// �洢�ռ��ʼ������ 
#define STACKINCREMENT 2	// �洢�ռ�������� 
typedef struct SqStack
{
	SElemType* base;	// ��ջ����֮ǰ������֮��base��ֵΪNULL 
	SElemType* top;		// ջ��ָ�� 
	int stacksize;		// ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ 
}SqStack;	// ˳��ջ

int InitStack(SqStack* S)//	����һ����ջS��
{
	// Ϊջ�׷���һ��ָ����С�Ĵ洢�ռ�
	(*S).base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!(*S).base)
		exit(0);		// �洢����ʧ�� 
	(*S).top = (*S).base;	// ջ��
	(*S).stacksize = STACK_INIT_SIZE;
	return 1;
}

int StackEmpty(SqStack S)// ��ջ�գ��򷵻�1�����򷵻�0
{
	if (S.top == S.base)
		return 1;
	else
		return 0;
}

int Push(SqStack* S, SElemType e)//	����Ԫ��eΪ�µ�ջ��Ԫ�ء�
{
	if ((*S).top - (*S).base >= (*S).stacksize)	// ջ����׷�Ӵ洢�ռ� 
	{
		(*S).base = (SElemType*)realloc((*S).base,
			((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!(*S).base)
			exit(0); // �洢����ʧ�� 
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++ = e;

	return 1;
}



int Pop(SqStack* S, SElemType* e)//	��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������1�����򷵻�0��
{
	if ((*S).top == (*S).base)
		return 0;
	*e = *--(*S).top;
	return 1;
}


void findindegree(ALGraph G, int indegree[])//�󶥵�����
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
	findindegree(G, indegree);//����������
	InitStack(&S);
	for (j = 0; j < G.vexnum; j++)
		if (!indegree[j])
			Push(&S, j);//��Ϊ0��ջ
	InitStack(T);
	count = 0;//������������
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
				ve[k] = ve[j] + *(p->info);//���緢��ʱ��ve
		}
	}
	if (count < G.vexnum)
	{
		printf("������ͼ�л�·\n");
		return 0;
	}
	else return 1;
}
//�ؼ��
int activity(ALGraph G)
{
	int vl[MAX_VERTEX_NUM];
	SqStack T;
	int i, j, k, ee, el;
	ArcNode* p;
	char dut, tag;

	if (!Topolog(G, &T)) // �������� 
		return 0;
	j = ve[0];
	for (i = 1; i < G.vexnum; i++) // j=Max(ve[]) ��ɵ��ֵ 
		if (ve[i] > j)
			j = ve[i];
	for (i = 0; i < G.vexnum; i++) // ��ʼ�������¼�����ٷ���ʱ��(���ֵ) 
		vl[i] = j; // ��ɵ�����緢��ʱ�� 
	while (!StackEmpty(T)) // ������������������vlֵ 
		for (Pop(&T, &j), p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			dut = *(p->info); // dut<j,k>
			if (vl[k] - dut < vl[j])
				vl[j] = vl[k] - dut;//��ٷ���ʱ��
		}
	printf(" j  k  dut  ee  el  tag\n");
	for (j = 0; j < G.vexnum; ++j) // ��ee,el�͹ؼ�� 
		for (p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			dut = *(p->info);
			ee = ve[j];
			el = vl[k] - dut;
			tag = (ee == el) ? '*' : ' ';
			// ����ؼ��
			printf("%2d %2d %3d %3d %3d    %c\n", j, k, dut, ee, el, tag);
		}
	printf("�ؼ��Ϊ:\n");
	for (j = 0; j < G.vexnum; ++j) // ͬ�� 
		for (p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			dut = *(p->info);
			if (ve[j] == vl[k] - dut)
				// ����ؼ�� 
				printf("%s��%s\n", G.vertices[j].data, G.vertices[k].data);
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