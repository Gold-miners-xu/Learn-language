#include<stdio.h>
int subtractProductAndSum(int n) {
	int sum = 0;
	int pro = 1;
	while (n > 0) {
		pro *= n % 10;
		sum += n % 10;
		n /= 10;
	}
	return pro - sum;
}
int main() {
	subtractProductAndSum(234);
	return 0;
}