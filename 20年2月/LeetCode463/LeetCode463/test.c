#include<stdio.h>
int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
	int rit = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			if (grid[i][j] == 1) {
				rit += 4;
				if (i > 0 && grid[i - 1][j] == 1)
					rit--;
				if (i < gridSize - 1 && grid[i + 1][j] == 1)
					rit--;
				if (j > 0 && grid[i][j - 1] == 1)
					rit--;
				if (j < (*gridColSize) - 1 && grid[i][j + 1] == 1)
					rit--;
			}
		}
	}
	return rit;
}
int main() {

	return 0;
}