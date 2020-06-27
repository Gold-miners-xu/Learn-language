#include<stack>
#include<iostream>
class MyQueue {
	stack<int> s1;
	stack<int> s2;
public:

	MyQueue() {

	}

	void push(int x) {
		s1.push(x);
	}

	int pop() {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		int x = s2.top();
		s2.pop();
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
		return x;
	}

	int peek() {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		int rit = s2.top();
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
		return rit;
	}


	bool empty() {
		return s1.empty();
	}
};