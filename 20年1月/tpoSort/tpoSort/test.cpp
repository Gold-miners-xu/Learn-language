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
////����������������
//int topo[MVNum];
//
//
////�ڽӱ�ṹ����ض���
//
////�߱�
//typedef struct ArcNode {
//	int adjvex;//�ñ���ָ��Ķ���λ�� 
//	struct ArcNode* nextarc;//ָ����һ���ߵ�ָ�� 
//	char info;    //�ͱ������Ϣ��Ȩֵ 
//}ArcNode;
//
//
////��ͷ����
//typedef struct VNode {
//	char data;
//	ArcNode* firstarc;//ָ����һ���ڵ�
//}VNode, AdjList[MVNum];
//
//
////�ڽӱ���Ȩ����ͼ
//typedef struct {
//	AdjList vertices;
//	int vexnum, arcnum;
//}ALGraph;
//
//
////��ջ����ض���
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
//	p = S;      //��P��ʱ���ջ��Ԫ�أ��ѱ��ͷ�
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
////�������ض�������λ�� 
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
////�������ڽӱ��������޻�ͼ 
//int CreateDAG(ALGraph& G) {
//	int i, j, k, weight;//Ȩֵ
//	char v1, v2;//��
//	ArcNode* p;
//	printf("\n[�������ܶ������ܱ���]:\n>>>");
//	scanf("%d %d", &G.vexnum, &G.arcnum);
//	for (i = 0; i < G.vexnum; i++) {         //������㣬�����ͷ���� 
//		printf("\n[���������붥����Ϣ]:\n>>>");
//		getchar();
//		scanf("%c", &G.vertices[i].data);
//		G.vertices[i].firstarc = NULL;
//	}
//	for (k = 0; k < G.arcnum; k++) {
//		printf("\n[��������߼�Ȩֵ�����ڽӱ�]:\n>>>");
//		getchar();
//		scanf("%c %c %d", &v1, &v2, &weight);
//		i = LocateVex(G, v1);//�������
//		j = LocateVex(G, v2);//�������
//		p = (ArcNode*)malloc(sizeof(ArcNode));
//		p->adjvex = j;
//		p->info = weight;
//
//		//ͷ��
//		p->nextarc = G.vertices[i].firstarc;
//		G.vertices[i].firstarc = p;
//	}
//	return  OK;
//}
//
//
////�������ÿ��������ȴ������� indegree[] 
//
////��ÿ����������
//void FindInDegree(ALGraph G, int indegree[]) {
//	//������ͼ�ڽӱ������,���ַ�����1���������ڽӱ�2�����������ڽӱ� 
//
//	//������ñ��������ڽӱ� 
//	ArcNode* p;  //��������
//
//	int i;//������
//
//
//	for (i = 0; i < G.vexnum; i++)//��ȳ�ʼ��Ϊ�� 
//		indegree[i] = 0;
//
//	for (i = 0; i < G.vexnum; i++) {//�����ڽӱ� 
//
//		p = G.vertices[i].firstarc;//�ڽӱ�ͷ
//
//		while (p != NULL) {
//
//			indegree[p->adjvex]++;//ͳ��ÿ���������
//
//			p = p->nextarc;
//		}
//	}
//}
//
//
////���������������������topo[] 
//int TopologicalSort(ALGraph G, int topo[]) {
//	//����ͼG�����ڽӱ�洢�ṹ
//	//��G�޻�·��������G��һ����������topo[]������OK�����򷵻�ERROR
//	int i;
//	ArcNode* p;
//	StackNode S;        //������ջ 
//	int indegree[MVNum];
//	FindInDegree(G, indegree);     //�����������ȣ���������indegree��
//	printf("���������:");
//	printf("\n-----indegree-----\n");
//	for (i = 0; i < G.vexnum; i++) {
//		printf("%d", indegree[i]);
//	}
//	printf("\n-----indegree-----\n");
//	InitStack(S);        //ջ��ʼ��Ϊ�� 
//	for (i = 0; i < G.vexnum; i++) {
//		if (indegree[i] == 0)
//			Push(S, i);       //���Ϊ������ջ 
//	}
//	int m = 0;
//	while (!StackEmpty(S)) {
//		Pop(S, i);        //��ջ������vi��ջ 
//		topo[m] = i;       //��vi������������������topo�� 
//		m++;         //������������ 
//		p = G.vertices[i].firstarc;    //pָ���һ���ڽӵ�
//		while (p != NULL) {
//			int k = p->adjvex;     //vkΪvi���ڽӵ� 
//			indegree[k]--;      //vi��ÿ���ڽӵ���ȼ�1 
//			if (indegree[k] == 0)
//				Push(S, k);      //�����Ϊ0����ջ 
//			p = p->nextarc;      //pָ��vi����һ���ڽӵ� 
//		}
//	}
//	if (m < G.vexnum)        //�ж����޻�· 
//		return ERROR;
//	else
//		return OK;
//}
//
//
//int CriticalPath(ALGraph G) {
//	//GΪ�ڽӱ�洢�������������G�ĸ���ؼ��
//	ArcNode* p;
//	int ve[MVNum];     //ve[MVNum]��¼ÿ���¼����緢��ʱ�� 
//	int vl[MVNum];     //vl[MVNum]��¼ÿ���¼���ٷ���ʱ�� 
//	int i, j, k, e, l;
//	if (!TopologicalSort(G, topo))
//		return ERROR;    //�������������㷨��ʹ�������б�����topo�У�������ʧ�ܣ���������򻷣�����ERROR
//	int n = G.vexnum;    //nΪ�������
//
//	for (i = 0; i < n; i++)
//		ve[i] = 0;     //��ÿ���¼������緢��ʱ���ó�ֵ0
//	/*-----------------�����˴�����ÿ���¼����緢��ʱ��-----------------*/
//	for (i = 0; i < n; i++) {
//		k = topo[i];     //ȡ���������������ж������k 
//		p = G.vertices[k].firstarc; //pָ��k�ĵ�һ���ڽӶ��� 
//		while (p != NULL) {    //���θ���k�������ڽӶ�������緢��ʱ�� 
//			j = p->adjvex;   //jΪ�ڽӶ������� 
//			if (ve[j] < ve[k] + p->info) //���¶���j�����緢��ʱ��ve[j] 
//				ve[j] = ve[k] + p->info;
//			p = p->nextarc;   //pָ��k����һ���ڽӶ��� 
//		}
//	}
//	for (i = 0; i < n; i++)    //��ÿ���¼�����ٷ���ʱ���ó�ֵve[n-1] 
//		vl[i] = ve[n - 1];
//	/*-----------------�������˴�����ÿ���¼���ٷ���ʱ��-----------------*/
//	for (i = n - 1; i >= 0; i--) {
//		k = topo[i];    //ȡ���������������ж������k 
//		p = G.vertices[k].firstarc; //pָ��k�ĵ�һ���ڽӶ���
//		while (p != NULL) {    //����k���ڽӵ㣬����k����ٷ���ʱ�� 
//			j = p->adjvex;   //jΪ�ڽӶ������� 
//			if (vl[k] > vl[j] - p->info) //���¶���k�����緢��ʱ��vl[k] 
//				vl[k] = vl[j] - p->info;
//			p = p->nextarc;   //pָ��k����һ���ڽӶ��� 
//		}
//	}
//	/*-----------------�ж�ÿһ��Ƿ�Ϊ�ؼ��-----------------*/
//	printf("�ؼ�·������:\n\n");
//	for (i = 0; i < n; i++) {
//		p = G.vertices[i].firstarc; //pָ��k�ĵ�һ���ڽӶ���
//		while (p != NULL) {
//			j = p->adjvex;   //jΪi���ڽӶ������� 
//			e = ve[i];    //����<vi,vj>�����翪ʼʱ�� 
//			l = vl[j] - p->info;  //����<vi,vj>����ٿ�ʼʱ�� 
//			if (e == l)     //��Ϊ�ؼ�������<vi,vj> 
//				printf("<%c,%c>", G.vertices[i].data, G.vertices[j].data);
//			p = p->nextarc;   //pָ��i����һ���ڽӶ��� 
//		}
//	}
//	printf("  ->end\n");
//	return OK;
//}
//
//
////�˵�����
//void Menu() {
//	printf("\n---------�˵�-------\n");
//	printf("\n1������ͼ�ṹ\n");
//	printf("\n2����������\n");
//	printf("\n3������ؼ�·��\n");
//	printf("\n0���˳�\n");
//	printf("\n--------------------\n");
//	printf("\n[���������ѡ��:]\n>>>");
//}
//
//
////������ 
////int main() {
//	int i, user;
//	ALGraph G;
//	while (true) {
//		Menu();
//		scanf("%d", &user);
//		switch (user) {
//		case 1: {
//			if (CreateDAG(G))
//				printf("\n�����ɹ�����\n");
//			break;
//		}
//		case 2: {
//			if (TopologicalSort(G, topo)) {
//				printf("��������������:\n\n");
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