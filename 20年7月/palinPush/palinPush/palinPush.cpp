#include<iostream>
#include<string>
using namespace std;
bool ispalind(const string& s) {
	size_t left = 0;
	size_t rit = s.size() - 1;
	while (left < rit) {
		if (s[left] != s[rit])
			return false;
		left++;
		rit--;
	}
	return true;
}
int main() {
	string a;
	string b;
	cin >> a;
	cin >> b;
	int count = 0;
	for (size_t i = 0; i < a.size(); i++) {
		string s = a;
		if (ispalind(s.insert(i, b)))
			count++;

	}
	if (ispalind(a.append(b)))
		count++;
	cout << count << endl;
	return 0;
}