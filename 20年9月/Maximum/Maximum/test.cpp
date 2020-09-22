#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int caculate(vector<int>& nums, int l, int r) {
	if (l > r)
		return 0;
	if (l == r)
		return nums[l];
	int ret = 0;
	int minus = 0;
	for (int i = l; i <= r; i++) {
		if (nums[i] < 0)
			minus++;
	}
	cout << minus << endl;
	if (minus % 2 == 0) {
		ret = 1;
		for (int i = l; i <= r; i++) {
			ret *= nums[i];
		}
	}
	else {
		int flag = 0;
		int mul = 1;
		for (int i = l; i <= r; i++) {
			if (flag != 0) {
				mul *= nums[i];
				flag = 2;
			}

			if (nums[i] < 0 && flag == 0)
				flag = 1;
		}
		if (flag == 2) {
			ret = mul;
		}
		flag = 0;
		mul = 1;
		for (int i = r; i >= l; i--) {
			if (flag != 0) {
				mul *= nums[i];
				flag = 2;
			}
			if (nums[i] < 0 && flag == 0)
				flag = 1;
		}
		if (flag == 2) {
			ret = max(ret, mul);
		}

	}
	return ret;
}
int maxProduct(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	int Max = nums[0];
	int left = 0, right = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 0) {
			Max = max(Max, 0);
			right = i - 1;
			Max = max(Max, caculate(nums, left, right));
			left = i + 1;
		}
	}
	Max = max(Max, caculate(nums, left, nums.size() - 1));
	return Max;
}