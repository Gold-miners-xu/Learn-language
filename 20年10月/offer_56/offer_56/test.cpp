#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) {
	int* num = new int[32];
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < 32; j++) {
			if ((nums[i] >> j) & 1 == 1)
				num[j]++;
		}
	}
	int N = 0;
	for (int i = 0; i < 32; i++) {
		if (num[i] % 3 != 0)
			N += (1 << i);
	}
	return N;
}
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> v(2, 0);
	int left, right;
	int mid;
	for (int i = 0; i < nums.size() && nums[i] < target; i++) {
		left = 0;
		right = nums.size() - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (nums[mid] < (target - nums[i]))
				left = mid + 1;
			else if (nums[mid] > (target - nums[i]))
				right = mid - 1;
			else
				break;
		}
		if (nums[mid] + nums[i] == target && i != mid) {
			v[0] = nums[mid];
			v[1] = nums[i];
			break;
		}
	}
	return v;
}