#include<stdio.h>
void Island(int** grid, int gridSize, int* gridColSize, int* area, int i, int j, int x) {
	if (x != 0 && i > 0 && grid[i - 1][j] == 1) {
		area++;
		Island(grid, gridSize, gridColSize, area, i - 1, j, 0);
	}
	if (x != 1 && i < gridSize - 1 && grid[i + 1][j] == 1) {
		area++;
		Island(grid, gridSize, gridColSize, area, i + 1, j, 1);
	}
	if (x != 2 && j > 0 && grid[i][j - 1] == 1) {
		area++;
		Island(grid, gridSize, gridColSize, area, i, j - 1, 2);
	}
	if (x != 3 && j < (*gridColSize) - 1 && grid[i][j + 1] == 1) {
		area++;
		Island(grid, gridSize, gridColSize, area, i, j + 1, 3);
	}

	return;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
	int max = 0;
	int area = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			if (grid[i][j] == 1)
				Island(grid, gridSize, gridColSize, &area, i, j, 0);
			if (max < area) {
				max = area;
				area = 0;
			}
		}
	}
	return max;
}
int main() {
	int grid[3][3] = { {0,1,1},{1,1,0},{1,0,1} };
	int gridSize = 3;
	int* gridColSize;
	int x = 3;
	gridColSize = &x;
	int max = 0;
	int area = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			if (grid[i][j] == 1)
				Island(grid, gridSize, gridColSize, &area, i, j, 0);
			if (max < area) {
				max = area;
				area = 0;
			}
		}
	}
//	maxAreaOfIsland(a,3,&x);
	return 0;
}