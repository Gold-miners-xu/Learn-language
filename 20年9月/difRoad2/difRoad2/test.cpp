#include<iostream>
#include<vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int>> move(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		if (obstacleGrid[0][i] == 0)
			move[0][i] = 1;
		else
			break;
	}
	for (int i = 0; i < m; i++) {
		if (obstacleGrid[i][0] == 0)
			move[i][0] = 1;
		else
			break;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (obstacleGrid[i][j] == 1)
				move[i][j] = 0;
			else
				move[i][j] = move[i - 1][j] + move[i][j - 1];
		}
	}
	return move[m - 1][n - 1];
}