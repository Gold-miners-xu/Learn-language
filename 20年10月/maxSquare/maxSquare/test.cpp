#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.size() == 0)
		return 0;
	int Max = 0;
	vector<int> v((matrix.size() + 1) * (matrix[0].size() + 1), 0);
	int n = matrix.size() + 1, m = matrix[0].size() + 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (matrix[i - 1][j - 1] == '1') {
				v[i * m + j] = min(v[(i - 1) * m + j - 1], v[(i - 1) * m + j]);
				v[i * m + j] = min(v[i * m + j], v[i * m + j - 1]);
				v[i * m + j]++;
				Max = max(Max, v[i * m + j]);
			}
		}
	}
	return Max * Max;
}
int main() 
{
	vector<vector<char>> v;
	vector<char> a(1, '0');
	vector<char> b(1, '1');
	v.push_back(a);
	v.push_back(b);
	maximalSquare(v);
	return 0;
}