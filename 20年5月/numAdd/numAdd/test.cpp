#include<iostream>
using namespace std;
class Solution {
public:
	class Sol {
	public:
		Sol() {
			_sum += _num;
			_num++;
		}
	};
	int Sum_Solution(int n) {
		_sum = 0;
		_num = 1;
		Sol Solnum[n];
		return _sum;
	}

	static int _sum;
	static int _num;
};
int Solution::_sum = 0;
int Solution::_num = 1;
int main() {

	return 0;
}