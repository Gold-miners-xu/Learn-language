#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> rit;
	if (matrix.size() == 0)
		return rit;
	int left = 0, up = 0, right = matrix[0].size() - 1, down = matrix.size() - 1;
	while (1) {
		for (int y = left; y <= right; y++) {
			rit.push_back(matrix[up][y]);
		}
		up++;
		if (down < up)
			break;
		for (int x = up; x <= down; x++) {
			rit.push_back(matrix[x][right]);
		}
		right--;
		if (right < left)
			break;
		for (int y = right; y >= left; y--) {
			rit.push_back(matrix[down][y]);
		}
		down--;
		if (down < up)
			break;
		for (int x = down; x >= up; x--) {
			rit.push_back(matrix[x][left]);
		}
		left++;
		if (right < left)
			break;
	}
	return rit;
}