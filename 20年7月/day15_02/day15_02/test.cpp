#include<vector>
#include<iostream>
using namespace std;
int mix(vector<int>& v) {
	int mix = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] < mix)
			mix = v[i];
	}
	return mix;
}
int findMinimum(int n, vector<int> left, vector<int> right) {
	// write code here
	int count = 0;
	int suml = 0;
	int sumr = 0;
	vector<int> Left;
	vector<int> Right;
	for (int i = 0; i < n; i++) {
		if (right[i] == 0)
			count += left[i];
		else if (left[i] == 0)
			count += right[i];
		else {
			Left.push_back(left[i]);
			suml += left[i];
			Right.push_back(right[i]);
			sumr += right[i];
		}
	}
	if (sumr > suml) {
		count += suml;
		count -= mix(Left);
		count += 2;
	}
	else {
		count += sumr;
		count -= mix(Right);
		count += 2;
	}
	cout << count << endl;
	return count;
}
int main() {
	vector<int> v1;
	vector<int> v2;
	v1.push_back(0);
	v1.push_back(7);
	v1.push_back(1);
	v1.push_back(6);
	v2.push_back(1);
	v2.push_back(5);
	v2.push_back(0);
	v2.push_back(6);
	findMinimum(4, v1, v2);
	return 0;
}