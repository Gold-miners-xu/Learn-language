#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int max = 0;
	int id;
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		while (s[i] >= '0' && s[i] <= '9') {
			i++;
			count++;
		}
		if (count > max) {
			max = count;
			id = i;
		}
		count = 0;
		i++;
	}
	for (int i = id - max; i < id; i++) {
		cout << s[i];
	}
	cout << endl;
	return 0;
}