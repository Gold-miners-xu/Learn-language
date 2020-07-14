#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	string s;
	while (getline(cin, s)) {
		string::iterator it = s.begin();
		vector<string> v;
		int count = 0;
		while (it != s.end()) {
			v.resize(count + 1);
			if (*it == ' ')
				it++;
			if (*it == '"') {
				it++;
				while (it != s.end() && *it != '"') {
					v[count].push_back(*it);
					it++;
				}
				it++;
			}
			else {
				while (it != s.end() && *it != ' ') {
					v[count].push_back(*it);
					it++;
				}
			}
			count++;
		}
		cout << count << endl;
		for (int i = 0; i < count; i++)
			cout << v[i] << endl;
		s.clear();
	}
	return 0;
}