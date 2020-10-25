#include<iostream>
#include<vector>
using namespace std;
int findDuplicate(vector<int>& nums) {
	int tmp, i = 0;
	while (i < nums.size()) {
		if (nums[i] == 0)
			break;
		tmp = nums[i];
		nums[i] = 0;
		i = tmp;
	}
	return i;
}