#include<iostream>
#include<vector>
using namespace std;
void Clear(vector<int> v, int num, int size) {
	vector<int> v2(size, 0);
	for (int i = 0; i < num; i++) {
		for (int j = size / 2, k = size, x = 0; x < size;) {
			v2[x++] = v[--k];
			v2[x++] = v[--j];
		}
		v.swap(v2);
	}
}

int  main() {
	int n;
	vector<vector<int>> v;
	while (cin >> n) {
		v.resize(n);
		for (int i = 0; i < n; i++) {
			int s, k;
			cin >> s >> k;
			v[i].reserve(2 * s);
			for (int j = 0; j < k; j++) {
				cin >> v[i][j];
			}
			Clear(v[i], k, 2 * s);
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++) {
				cout << v[i][j];
				if (i != v.size() && j != v[i].size())
					cout << " ";
			}
		}
	}
	return 0;
}