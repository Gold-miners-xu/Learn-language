#include<string>
#include<iostream>
#include <utility> 
using namespace std;
int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		int carry = 0;
		int len1 = s1.size(), len2 = s2.size();
		string sum;
		while (len1 > 0 || len2 > 0) {
			char tmp;
			if (len1 > 0 && len2 > 0)
				tmp = s1[--len1] + s2[--len2] + carry - '0';
			else if (len1 > 0)
				tmp = s1[--len1] + carry;
			else
				tmp = s2[--len2] + carry;
			carry = 0;
			if (tmp > '9') {
				tmp -= 10;
				carry = 1;
			}
			sum.push_back(tmp);
		}
		if (carry != 0)
			sum.push_back('1');
		int i = 0, j = sum.size() - 1;
		while (i < j) {
			swap(sum[i], sum[j]);
			i++;
			j--;
		}
		cout << sum << endl;
	}
	return 0;
}