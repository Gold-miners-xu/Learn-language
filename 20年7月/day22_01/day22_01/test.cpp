#include<iostream>
#include<vector>
using namespace std;
int choice(int a, int b) {
	if (a >= b)
		return b;
	while (a != 0) {
		int tmp = b % a;
		b = a;
		a = tmp;
	}
	return b;
}
int main() {
	int n, a;
	while (cin >> n >> a) {
		vector<int> b;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			b.push_back(tmp);
		}
		for (int j = 0; j < n; j++) {
			a += choice(a, b[j]);
		}
		cout << a << endl;
	}
	return 0;
}