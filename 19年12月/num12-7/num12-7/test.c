#include<stdio.h>
#include<stdlib.h>
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
	if (K == 0) {
		*returnSize = ASize;
		return A;
	}
	int* a = calloc(ASize + 5, sizeof(int));
	int i = ASize - 1;
	int cont = 0;
	int tmp = K;
	for (int j = 0; i >= 0 || tmp > 0; j++) {
		if (i >= 0) {
			tmp += A[i];
			a[j] = tmp % 10;
			tmp /= 10;
			cont++;
			i--;
		}
		else {
			a[j] = tmp % 10;
			tmp /= 10;
			cont++;
		}

	}
	*returnSize = cont;
	int* x = calloc(*returnSize, sizeof(int));
	for (int y = 0; y < *returnSize; y++) {
		x[y] = a[*returnSize - y - 1];
	}
	return x;

}
//数组形式的整数加法
//输入：A = [1,2,0,0], K = 34
//输出：[1, 2, 3, 4]
//解释：1200 + 34 = 1234
int main() {
	int a[4] = { 1,2,0,0 };

	int size = 0;

	int* b = addToArrayForm(a, 4, 34, &size);
	printf("%d", 0 % 10);
		return 0;
}