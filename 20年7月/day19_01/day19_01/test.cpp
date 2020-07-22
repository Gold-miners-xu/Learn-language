#include<iostream>
#include<vector>
using namespace std;
void Print(vector<int>& v) {
	for (int i = 0; v[i] != 0; i++) {
		int sum = 0;
		while (v[i] > 1) {
			if (v[i] == 2) {
				sum++;
				break;
			}
			int tmp = v[i] / 3;
			v[i] = v[i] % 3;
			v[i] += tmp;
			sum += tmp;
		}
		cout << sum << endl;
	}
}
int main() {
	vector<int> v;
	int tmp;
	do {
		cin >> tmp;
		v.push_back(tmp);
	} while (tmp != 0);
	Print(v);
	return 0;
}