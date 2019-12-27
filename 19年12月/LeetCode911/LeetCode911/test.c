#include<stdio.h>
#include<math.h>
int brokenCalc(int X, int Y) {
	int sum = 0;
	if (X >= Y) {
		sum = X - Y;
		return sum;
	}
	while (X != Y) {
		if (Y % 2 == 0 && Y > X) {
			Y = Y / 2;
			sum++;
		}
		else {
			Y = Y + 1;
			sum++;
		}
	}
	return sum;
}
int main() {
	brokenCalc(2, 3);
	return 0;
}