#include<iostream>
#include<string>
using namespace std;
void swap(string& s, int begin, int end) {
	while (begin < end) {
		char tmp = s[begin];
		s[begin] = s[end];
		s[end] = tmp;
		begin++;
		end--;
	}
}
int main() {
	string s;
	getline(cin, s);
	swap(s, 0, s.size() - 1);
	size_t left = 0;
	size_t rit = 0;
	while (rit < s.size()) {
		if (s[rit] == ' ') {
			swap(s, left, rit - 1);
			left = rit + 1;
		}
		rit++;
	}
	swap(s, left, s.size() - 1);
	cout << s << endl;
	return 0;
}
