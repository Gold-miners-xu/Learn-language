#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool Find(vector<vector<char>>& board, int i, int j, string word, int size);
bool exist(vector<vector<char>>& board, string word) {
	if (board.size() == 0 || word.size() == 0)
		return false;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == word[0]) {
				if (Find(board, i, j, word, 0))
					return true;
			}
		}
	}
	return false;
}
bool Find(vector<vector<char>>& board, int i, int j, string word, int size) {
	if (board[i][j] != word[size]) {
		return false;
	}
	if (size == (word.size() - 1))
		return true;
	char tmp = board[i][j];
	board[i][j] = '/';
	if ((i - 1) >= 0) {
		if (Find(board, i - 1, j, word, size + 1))
			return true;
	}
	if ((i + 1) < board.size()) {
		if (Find(board, i + 1, j, word, size + 1))
			return true;
	}
	if ((j - 1) >= 0) {
		if (Find(board, i, j - 1, word, size + 1))
			return true;
	}
	if ((j + 1) < board[0].size()) {
		if (Find(board, i, j + 1, word, size + 1))
			return true;
	}
	board[i][j] = tmp;
	return false;
}
int main() {
	vector<vector<char>> v = {
		{'A','B','C','E' }, { 'S','F','C','S' }, { 'A','D','E','E' }
	};
	string word = "ABCCED";
	exist(v, word); 
	return 0;
}