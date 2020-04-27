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
//À©ÈÝ
void inCapacity(heap* hp) {
	hp->val = realloc(hp->val, sizeof(int) * 2 * hp->size);
	if (hp->val == NULL)
		printf("À©ÈÝÊ§°Ü\n");
	hp->capacity *= 2;
}
void insert(heap* hp, Data x) {
	if (hp->size == hp->capacity) {
		inCapacity(hp);
	}
	hp->val[hp->size] = x;
	int child = hp->size;
	hp->size++;
	while (child > 0 && hp->val[child] < hp->val[(child - 1) / 2]) {
		swap(hp->val, child, (child - 1) / 2);
		child = (child - 1) / 2;
	}
}