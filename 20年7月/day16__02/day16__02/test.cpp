#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool insert(string s, vector<pair<string, int>>& v) {
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i].first == s) {
			v[i].second++;
			return true;
		}
	}
	return false;
}
char pars(string s, vector<pair<string, int>>& v) {
	int size = 0;
	for (size_t i = 0; i < s.size(); i += 2) {
		string tmp;
		if (i + 1 < s.size() && s[i + 1] != ' ' && s[i + 1] != '0') {
			tmp.append(s, i, 5);
			i += 4;
		}
		else if (i + 1 < s.size() && s[i + 1] != ' ') {
			tmp.append(s, i, 2);
			i++;
		}
		else
			tmp.push_back(s[i]);
		insert(tmp, v);
		size++;
	}
	if (v[13].second > 0 && v[14].second > 0)
		return 'B';
	if (size == 5)
		return 'l';
	if (size == 4)
		return 'B';
	if (size == 3)
		return 't';
	if (size == 2)
		return 'D';
	if (size == 1)
		return 'd';
}
void make(vector<pair<string, int>>& v) {
	v.push_back(make_pair("3", 0));
	v.push_back(make_pair("4", 0));
	v.push_back(make_pair("5", 0));
	v.push_back(make_pair("6", 0));
	v.push_back(make_pair("7", 0));
	v.push_back(make_pair("8", 0));
	v.push_back(make_pair("9", 0));
	v.push_back(make_pair("10", 0));
	v.push_back(make_pair("J", 0));
	v.push_back(make_pair("Q", 0));
	v.push_back(make_pair("K", 0));
	v.push_back(make_pair("A", 0));
	v.push_back(make_pair("2", 0));
	v.push_back(make_pair("joker", 0));
	v.push_back(make_pair("JOKER", 0));
}
bool comp(vector<pair<string, int>>& v1, vector<pair<string, int>>& v2) {
	int i = 0;
	while (i < v1.size()) {
		if (v1[i].second > 0)
			break;
		i++;
	}
	int j = 0;
	while (j < v2.size()) {
		if (v2[j].second > 0)
			break;
		j++;
	}
	if (i > j)
		return true;
	else
		return false;
}
int main() {
	string s;
	while (getline(cin, s)) {
		string s1;
		string s2;
		size_t found = s.find('-');
		s1.append(s.begin(), s.begin() + found);
		s2.append(s.begin() + found + 1, s.end());
		vector<pair<string, int>> v1;
		make(v1);
		vector<pair<string, int>> v2(v1);
		char c1 = pars(s1, v1);
		char c2 = pars(s2, v2);
		if (c1 == 'B' && c2 != 'B')
			cout << s1 << endl;
		else if (c2 == 'B' && c1 != 'B')
			cout << s2 << endl;
		else if (c1 != c2)
			cout << "ERROR" << endl;
		else {
			if (comp(v1, v2))
				cout << s1 << endl;
			else
				cout << s2 << endl;
		}

	}
	return 0;
}