#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
	int num;
	long rit = 0;
	cin >> num;
	vector<int> v;
	v.reserve(num * 3);
	int tmp;
	for (int i = 0; i < num * 3; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i = (num * 3) - 2; i >= num; i -= 2) {
		rit += v[i];
	}
	cout << rit << endl;
	return 0;
}