#include<iostream>
#include<vector>
#include <climits>
using namespace std;
int main() {
	int M, N;
	while (cin >> N >> M) {
		vector<int> v(M + 1, INT_MAX);
		v[N] = 0;
		for (int i = N; i <= M; i++) {
			if (v[i] == INT_MAX)
				continue;
			for (int j = 2; (j * j) <= i; j++) {
				if (i % j == 0) {
					if (i + j <= M)
						v[i + j] = v[i + j] < (v[i] + 1) ? v[i + j] : (v[i] + 1);
					if (i + (i / j) <= M)
						v[i + (i / j)] = v[i + (i / j)] < (v[i] + 1) ? v[i + (i / j)] : (v[i] + 1);
				}
			}
		}
		if (v[M] == INT_MAX)
			cout << "-1" << endl;
		else
			cout << v[M] << endl;
	}
	return 0;
}