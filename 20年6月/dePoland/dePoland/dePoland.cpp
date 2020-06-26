#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens[i] == "+" || tokens[i] == "-"
				|| tokens[i] == "*" || tokens[i] == "/") {
				int rit = s.top();
				s.pop();
				int left = s.top();
				s.pop();
				if (tokens[i] == "+") {
					s.push(left + rit);
				}
				else if (tokens[i] == "-") {
					s.push(left - rit);
				}
				else if (tokens[i] == "*") {
					s.push(left * rit);
				}
				else {
					s.push(left / rit);
				}
			}
			else {
				s.push(stoi(tokens[i]));
			}
		}
		return s.top();
	}
};