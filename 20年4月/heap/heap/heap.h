#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Data int
//�Ѷ���
typedef struct heap {
	Data* val;
	int size;
	int capacity;
}heap;
//�ѳ�ʼ��
void Init(Data* val, heap* hp, int size);
//���¶���
void down(Data* val, int parent, int size);
//��������
void swap(Data* val, int i, int j);
//����
void build(heap* hp);
//����Ԫ��
void insert(heap* hp, Data);