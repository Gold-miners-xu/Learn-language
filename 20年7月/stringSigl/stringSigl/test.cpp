#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;
	string::iterator it = s.begin();
	while (it != s.end()) {
		string::iterator it2 = s.begin();
		while (it2 != it) {
			if (*it2 == *it)
				break;
			it2++;
		}
		if (it2 == it)
			cout << *it;
		it++;
	}
	cout << endl;
	return 0;
}