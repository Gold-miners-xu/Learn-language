#include"sort_mer.h"

int main() {
	int a[] = { 2,6,9 ,1,3,6,8,9,36 };
	int* b = (int*)malloc(sizeof(int) * 8);
	//Mer(a, 0, 2, 7, b);
	sortMer(a, 9);

	return 0;
}