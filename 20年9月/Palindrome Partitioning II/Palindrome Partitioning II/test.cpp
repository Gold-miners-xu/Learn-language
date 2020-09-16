#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int minCut(string s) {
	if (s.size() == 0)
		return 0;
	vector<int> Min(s.size());
	for (int i = 0; i < s.size(); i++)
		Min[i] = i;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j <= i && i + j <= s.size(); j++) {
			if (s[i - j] == s[i + j]) {
				if (i == j)
					Min[i + j] = 0;
				else {
					Min[i + j] = min(Min[i + j], Min[i - j - 1] + 1);
				}
			}
			else {
				break;
			}
		}
		for (int j = 1; j <= i + 1 && i + j <= s.size(); j++) {
			if (s[i - j + 1] == s[i + j]) {
				if (i + 1 == j)
					Min[i + j] = 0;
				else
					Min[i + j] = min(Min[i + j], Min[i - j] + 1);
			}
			else
				break;
		}
	}
	return Min[s.size() - 1];
}