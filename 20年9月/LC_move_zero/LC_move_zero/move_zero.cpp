#include<iostream>
#include<vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
	int zero = 0;
	for (int i = 0, j = 0; j < nums.size() - zero; j++, i++) {
		while (i < nums.size() && nums[i] == 0) {
			zero++;
			i++;
		}
		if (i < nums.size())
			nums[j] = nums[i];
	}
	for (int i = nums.size() - zero; i < nums.size(); i++) {
		nums[i] = 0;
	}

}