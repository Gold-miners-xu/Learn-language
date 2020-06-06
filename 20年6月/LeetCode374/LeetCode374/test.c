#include<stdio.h>
int guessNumber(int n) {
	int left = 1;
	int rit = n;
	while (left < rit) {
		int mid = left + (rit - left) / 2;
		if (guess(mid) == 1) {
			left = mid + 1;
		}
		else if (guess(mid) == -1) {
			rit = mid - 1;
		}
		else {
			return mid;
		}
	}
	return left;
}