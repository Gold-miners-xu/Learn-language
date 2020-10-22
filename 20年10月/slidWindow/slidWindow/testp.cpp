#include<iostream>
#include<vector>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	int n = nums.size();
	vector<int> left(n, 0);
	vector<int> right(n, 0);
	vector<int> ret(n - k + 1, 0);
	if (k == 0)
		return ret;
	if (k == 1)
		return nums;
	int max;
	for (int i = 0; i < n; i++) {
		if ((i + 1) % k == 1)
			max = nums[i];
		if (nums[i] > max)
			max = nums[i];
		left[i] = max;
	}
	max = nums[n - 1];
	for (int i = n - 1; i >= 0; i--) {
		if ((i + 1) % k == 0)
			max = nums[i];
		if (nums[i] > max)
			max = nums[i];
		right[i] = max;
	}
	for (int i = 0; i < ret.size(); i++) {
		ret[i] = left[i + k - 1] > right[i] ? left[i + k - 1] : right[i];
	}
	return ret;
}