#include<stdio.h>
int distributeCandies(int* candies, int candiesSize) {
	int sum = 0;
	int rit[200005] = { 0 };

	for (int i = 0; i < candiesSize; i++) {
		int tmp = candies[i] + 100000;
		if (rit[tmp] == 0) {
			sum++;
		}
		rit[tmp] += 1;
	}
	if (sum >= candiesSize / 2)
		return candiesSize / 2;
	return sum;
}
int main() {
	int sum[4] = { 1000,1,1,1 };
	distributeCandies(sum, 4);
	return 0;
}