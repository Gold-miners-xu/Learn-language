//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//
//#define MVNum 100
//#define OK 1
//#define ERROR 0
//
//
////定义拓扑排序数组
//int topo[MVNum];
//
//
////邻接表结构的相关定义
//
////边表
//typedef struct ArcNode {
//	int adjvex;//该边所指向的顶点位置 
//	struct ArcNode* nextarc;//指向下一条边的指针 
//	char info;    //和边相关信息，权值 
//}ArcNode;
//
//
////表头结点表
//typedef struct VNode {
//	char data;
//	ArcNode* firstarc;//指向下一个节点
//}VNode, AdjList[MVNum];
//
//
////邻接表，带权有向图
//typedef struct {
//	AdjList vertices;
//	int vexnum, arcnum;
//}ALGraph;
//
//
////链栈的相关定义
//typedef struct StackLink {
//	int data;
//	struct StackLink* next;
//}StackLink, * StackNode;
//
//
//int InitStack(StackNode& S) {
//	S = NULL;
//	return OK;
//}
//
//
//int Push(StackNode& S, int e) {
//	StackNode p;
//	p = (StackLink*)malloc(sizeof(StackLink));
//	p->data = e;
//	p->next = S;
//	S = p;
//	return OK;
//}
//
//
//int Pop(StackNode& S, int& e) {
//	StackNode p;
//	p = (StackLink*)malloc(sizeof(StackLink));
//	if (S == NULL)
//		return  ERROR;
//	e = S->data;
//	p = S;      //用P临时存放栈顶元素，已备释放
//	S = S->next;
//	free(p);
//	return OK;
//}
//
//
//int GetTop(StackNode S) {
//	if (S != NULL)
//		return S->data;
//}
//
//
//int StackEmpty(StackNode S) {
//	if (S != NULL)
//		return ERROR;
//	else
//		return OK;
//}
//
//
////函数返回顶点所在位置 
//int LocateVex(ALGraph G, char c) {
//	int i;
//	for (i = 0; i < G.vexnum; ++i) {
//		if (c == G.vertices[i].data)
//			return i;
//	}
//	return -1;
//}
//
//
////函数用邻接表创建有向无环图 
//int CreateDAG(ALGraph& G) {
//	int i, j, k, weight;//权值
//	char v1, v2;//边
//	ArcNode* p;
//	printf("\n[请输入总顶点与总边数]:\n>>>");
//	scanf("%d %d", &G.vexnum, &G.arcnum);
//	for (i = 0; i < G.vexnum; i++) {         //输入各点，构造表头结点表 
//		printf("\n[请依次输入顶点信息]:\n>>>");
//		getchar();
//		scanf("%c", &G.vertices[i].data);
//		G.vertices[i].firstarc = NULL;
//	}
//	for (k = 0; k < G.arcnum; k++) {
//		printf("\n[请输入各边及权值构造邻接表]:\n>>>");
//		getchar();
//		scanf("%c %c %d", &v1, &v2, &weight);
//		i = LocateVex(G, v1);//保存变量
//		j = LocateVex(G, v2);//保存变量
//		p = (ArcNode*)malloc(sizeof(ArcNode));
//		p->adjvex = j;
//		p->info = weight;
//
//		//头插
//		p->nextarc = G.vertices[i].firstarc;
//		G.vertices[i].firstarc = p;
//	}
//	return  OK;
//}
//
//
////函数求出每个顶点入度存入数组 indegree[] 
//
////求每个顶点的入度
//void FindInDegree(ALGraph G, int indegree[]) {
//	//求有向图邻接表顶点入度,两种方法：1、建立逆邻接表，2、遍历整个邻接表 
//
//	//这里采用遍历整个邻接表 
//	ArcNode* p;  //遍历链表
//
//	int i;//计数器
//
//
//	for (i = 0; i < G.vexnum; i++)//入度初始化为零 
//		indegree[i] = 0;
//
//	for (i = 0; i < G.vexnum; i++) {//遍历邻接表 
//
//		p = G.vertices[i].firstarc;//邻接表头
//
//		while (p != NULL) {
//
//			indegree[p->adjvex]++;//统计每个结点的入度
//
//			p = p->nextarc;
//		}
//	}
//}
//
//
////函数获得拓扑排序结果数组topo[] 
//int TopologicalSort(ALGraph G, int topo[]) {
//	//有向图G采用邻接表存储结构
//	//若G无回路，则生成G的一个拓扑序列topo[]并返回OK，否则返回ERROR
//	int i;
//	ArcNode* p;
//	StackNode S;        //定义链栈 
//	int indegree[MVNum];
//	FindInDegree(G, indegree);     //求出各顶点入度，存入数组indegree中
//	printf("各顶点入度:");
//	printf("\n-----indegree-----\n");
//	for (i = 0; i < G.vexnum; i++) {
//		printf("%d", indegree[i]);
//	}
//	printf("\n-----indegree-----\n");
//	InitStack(S);        //栈初始化为空 
//	for (i = 0; i < G.vexnum; i++) {
//		if (indegree[i] == 0)
//			Push(S, i);       //入度为零者入栈 
//	}
//	int m = 0;
//	while (!StackEmpty(S)) {
//		Pop(S, i);        //将栈顶顶点vi出栈 
//		topo[m] = i;       //将vi保存在拓扑序列数组topo中 
//		m++;         //对输出顶点计数 
//		p = G.vertices[i].firstarc;    //p指向第一个邻接点
//		while (p != NULL) {
//			int k = p->adjvex;     //vk为vi的邻接点 
//			indegree[k]--;      //vi的每个邻接点入度减1 
//			if (indegree[k] == 0)
//				Push(S, k);      //若入度为0则入栈 
//			p = p->nextarc;      //p指向vi的下一个邻接点 
//		}
//	}
//	if (m < G.vexnum)        //判断有无回路 
//		return ERROR;
//	else
//		return OK;
//}
//
//
//int CriticalPath(ALGraph G) {
//	//G为邻接表存储的有向网，输出G的各项关键活动
//	ArcNode* p;
//	int ve[MVNum];     //ve[MVNum]记录每个事件最早发生时间 
//	int vl[MVNum];     //vl[MVNum]记录每个事件最迟发生时间 
//	int i, j, k, e, l;
//	if (!TopologicalSort(G, topo))
//		return ERROR;    //调用拓扑排序算法，使拓扑序列保存在topo中；若调用失败，则存在有向环，返回ERROR
//	int n = G.vexnum;    //n为顶点个数
//
//	for (i = 0; i < n; i++)
//		ve[i] = 0;     //个每个事件的最早发生时间置初值0
//	/*-----------------按拓扑次序求每个事件最早发生时间-----------------*/
//	for (i = 0; i < n; i++) {
//		k = topo[i];     //取得拓扑排序序列中顶点序号k 
//		p = G.vertices[k].firstarc; //p指向k的第一个邻接顶点 
//		while (p != NULL) {    //依次更新k的所有邻接顶点的最早发生时间 
//			j = p->adjvex;   //j为邻接顶点的序号 
//			if (ve[j] < ve[k] + p->info) //更新顶点j的最早发生时间ve[j] 
//				ve[j] = ve[k] + p->info;
//			p = p->nextarc;   //p指向k的下一个邻接顶点 
//		}
//	}
//	for (i = 0; i < n; i++)    //给每个事件的最迟发生时间置初值ve[n-1] 
//		vl[i] = ve[n - 1];
//	/*-----------------按逆拓扑次序求每个事件最迟发生时间-----------------*/
//	for (i = n - 1; i >= 0; i--) {
//		k = topo[i];    //取得拓扑排序序列中顶点序号k 
//		p = G.vertices[k].firstarc; //p指向k的第一个邻接顶点
//		while (p != NULL) {    //根据k的邻接点，更新k的最迟发生时间 
//			j = p->adjvex;   //j为邻接顶点的序号 
//			if (vl[k] > vl[j] - p->info) //更新顶点k的最早发生时间vl[k] 
//				vl[k] = vl[j] - p->info;
//			p = p->nextarc;   //p指向k的下一个邻接顶点 
//		}
//	}
//	/*-----------------判断每一活动是否为关键活动-----------------*/
//	printf("关键路径如下:\n\n");
//	for (i = 0; i < n; i++) {
//		p = G.vertices[i].firstarc; //p指向k的第一个邻接顶点
//		while (p != NULL) {
//			j = p->adjvex;   //j为i的邻接顶点的序号 
//			e = ve[i];    //计算活动<vi,vj>的最早开始时间 
//			l = vl[j] - p->info;  //计算活动<vi,vj>的最迟开始时间 
//			if (e == l)     //若为关键活动则输出<vi,vj> 
//				printf("<%c,%c>", G.vertices[i].data, G.vertices[j].data);
//			p = p->nextarc;   //p指向i的下一个邻接顶点 
//		}
//	}
//	printf("  ->end\n");
//	return OK;
//}
//
//
////菜单函数
//void Menu() {
//	printf("\n---------菜单-------\n");
//	printf("\n1、创建图结构\n");
//	printf("\n2、拓扑排序\n");
//	printf("\n3、计算关键路径\n");
//	printf("\n0、退出\n");
//	printf("\n--------------------\n");
//	printf("\n[请输入你的选择:]\n>>>");
//}
//
//
////主函数 
////int main() {
//	int i, user;
//	ALGraph G;
//	while (true) {
//		Menu();
//		scanf("%d", &user);
//		switch (user) {
//		case 1: {
//			if (CreateDAG(G))
//				printf("\n创建成功……\n");
//			break;
//		}
//		case 2: {
//			if (TopologicalSort(G, topo)) {
//				printf("拓扑排序结果如下:\n\n");
//				for (i = 0; i < G.vexnum; i++)
//					printf("%c->", G.vertices[topo[i]].data);
//				printf("end\n");
//			}
//			break;
//		}
//		case 3: {
//			CriticalPath(G);
//			break;
//		}
//		case 0:exit(0);
//		}
//	}
//	return 0;
//}