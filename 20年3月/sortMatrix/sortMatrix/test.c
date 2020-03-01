#include<stdio.h>
bool searchMatrix(int** matrix, int m, int n, int target) {
	if (m == 0 || n == 0)
		return false;
	int x = m - 1, y = 0;
	while (x >= 0 && y < n) {
		if (target > matrix[y][x]) {
			y++;
		}
		else if (target < matrix[y][x]) {
			x--;
		}
		else {
			return true;
		}
		printf("%d,%d", x, y);
	}

	return false;
}
//m * nÅÅÐò¾ØÕóÕÒÊý×Ötarget
int main() {
	return 0;
}
