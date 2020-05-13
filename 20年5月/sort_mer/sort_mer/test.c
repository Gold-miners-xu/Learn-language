#include"sort_mer.h"

int main() {
	int a[] = { 5,1,1,2,0,0 };
	int* b = (int*)malloc(sizeof(int) * 8);
	//Mer(a, 0, 2, 7, b);
	sortMer(a,6);

	return 0;
}