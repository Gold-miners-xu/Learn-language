#include<iostream>
#include<vector>
using namespace std;
vector<int> singleNumbers(vector<int>& nums) {
	vector<int> ret(2, 0);
	int mul = 0;
	for (int i = 0; i < nums.size(); i++) {
		mul ^= nums[i];
	}
	int num = 0;
	for (int i = mul; i >= 0; i /= 2) {
		if ((i & 1) != 0)
			break;
		num++;
	}
	ret[0] = mul;
	for (int i = 0; i < nums.size(); i++) {
		if (((nums[i] >> num) & 1) != 0) {
			ret[0] ^= nums[i];
		}

	}
	ret[1] = mul ^ ret[0];
	return ret;
}