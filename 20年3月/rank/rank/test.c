#include<stdio.h>
#include<stdlib.h>
void Babllsort(void* base, int nitems) {
	int* i = base;
	int* k = i + nitems;
	while (i < k) {
		int* j = i + 1;
		while (j < k) {
			if (*i > * j) {
				int tmp = *i;
				*i = *j;
				*j = tmp;
			}
			j++;
		}
		i++;
	}
}
int compare(const void* a, const void* b) {
	return (*(int*)a) - (*(int*)b);//从小到大
	//return *(int *)b-*(int *)a;//从大到小
}
int main() {
	//int a[] = { 2,5,6,3,1,4 };
	//Babllsort(a, 6);
	//for (int i = 0; i < 6; i++) {
	//	printf("%d", a[i]);
	//}
	//int a[] = { 5,2,4,6,9 };
	char a[] = { 'a','c','n','x','s' };
	qsort(a, 5, sizeof(char), compare);
	for (int i = 0; i < 5; i++) {
		printf("%c", a[i]);
	}
	return 0;
}



//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}