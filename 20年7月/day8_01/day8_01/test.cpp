#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool islenth(vector<string> v, size_t n) {
	for (int i = 1; i < n; i++) {
		if (v[i - 1].size() > v[i].size())
			return false;
	}
	return true;
}
bool isdec(vector<string> v, size_t n) {
	for (int i = 0; i < n - 1; i++) {
		if (v[i].compare(v[i + 1]) > 0)
			return false;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	vector<string> v;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (isdec(v, v.size()) && islenth(v, v.size()))
		cout << "both" << endl;
	else if (isdec(v, v.size()))
		cout << "lexicographically" << endl;
	else if (islenth(v, v.size()))
		cout << "lengths" << endl;
	else
		cout << "none" << endl;
	return 0;
}