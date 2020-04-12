#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Data int
//堆定义
typedef struct heap {
	Data* val;
	int size;
	int capacity;
}heap;
//堆初始化
void Init(Data* val, heap* hp, int size);
//向下对齐
void down(Data* val, int parent, int size);
//交换函数
void swap(Data* val, int i, int j);
//建堆
void build(heap* hp);
//插入元素
void insert(heap* hp, Data);