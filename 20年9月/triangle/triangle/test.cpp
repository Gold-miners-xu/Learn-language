#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int minimumTotal(vector<vector<int> >& triangle) {
	vector<vector<int>> dp;
	dp.resize(triangle.size());
	for (int i = 0; i < dp.size(); i++) {
		dp[i].resize(triangle[i].size());
		for (int j = 0; j < dp[i].size(); j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = triangle[i][j];
			}
			else if (j == 0) {
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == dp[i].size() - 1) {
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else
				dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}
	int mn = dp[dp.size() - 1][0];
	for (int i = 1; i < dp[dp.size() - 1].size(); i++)
		mn = min(mn, dp[dp.size() - 1][i]);
	return mn;
}
int main() {
	vector<vector<int>> v;
	v.resize(4);
	v[0].resize(1);
	v[1].resize(2);
	v[2].resize(3);
	v[3].resize(4);
	v[0][0] = 2;
	v[1][0] = 3;
	v[1][1] = 4;
	v[2][0] = 6;
	v[2][1] = 5;
	v[2][2] = 7;
	v[3][0] = 4;
	v[3][1] = 1;
	v[3][2] = 8;
	v[3][3] = 3;
	minimumTotal(v);
	return 0;
}