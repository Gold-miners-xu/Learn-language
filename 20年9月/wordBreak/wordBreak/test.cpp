#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool findWord(vector<string>& wordDict, string s) {
	for (int i = 0; i < wordDict.size(); i++) {
		if (wordDict[i].compare(s) == 0)
			return true;
	}
	return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
	vector<int> card;
	int len = s.size();
	if (wordDict.size() == 0)
		return false;
	for (int i = 0; i < len; i++) {
		if (findWord(wordDict, s.substr(0, i + 1))) {
			card.resize(card.size() + 1);
			card[card.size() - 1] = i;
		}
		for (int j = 0; j < card.size(); j++) {
			if (findWord(wordDict, s.substr(card[j] + 1, i - card[j]))) {
				card.resize(card.size() + 1);
				card[card.size() - 1] = i;
				break;
			}
		}
	}
	if (card.size() != 0 && card[card.size() - 1] == len - 1)
		return true;

	return false;
}
int main() {
	string s;
	s = "applepenapple";
	vector<string> vs(2);
	vs[0] = "apple";
	vs[1] = "pen";
	wordBreak(s, vs);
	return 0;
}