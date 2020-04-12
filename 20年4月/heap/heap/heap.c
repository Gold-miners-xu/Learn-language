#include"heap.h"

void swap(Data* val, int i, int j) {
	Data tmp = val[i];
	val[i] = val[j];
	val[j] = tmp;
}
void down(Data* val, int parent, int size) {
	int child = parent * 2 + 1;
	
	while (child < size) {
		if (child + 1 < size && val[child] > val[child + 1]) {
			child++;
		}
		if (val[child] < val[parent]) {
			swap(val, child, parent);
		}
		else {
			break;
		}
		parent = child;
		child = parent * 2 + 1;
	}

}
void Init(Data* val, heap* hp,int size) {
	hp->val = (Data*)malloc(sizeof(Data) * size);
	memcpy(hp->val, val, sizeof(Data) * size);
	hp->size = size;
	hp->capacity = size;
	build(hp);
}
void build(heap* hp) {
	int parent = (hp->size - 2) / 2;
	while (parent >= 0) {
		down(hp->val, parent, hp->size);
		parent--;
	}
}