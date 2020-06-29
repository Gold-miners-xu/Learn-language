#include<iostream>
#include<string>
using namespace std;
int main() {
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	string::iterator it = s2.begin();
	while (it != s2.end()) {
		char tmp = *it;
		size_t f;
		while (1) {
			f = s1.find(tmp);
			if (f == string::npos)
				break;
			s1.erase(f, 1);

		}
		it++;
	}
	cout << s1 << endl;
}