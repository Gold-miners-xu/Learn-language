#include<iostream>
#include<vector>
using namespace std;
int findMin(vector<int>& nums) {
	int mid;
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		mid = (left + right) / 2;
		if (nums[mid] < nums[right]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}

	}
	return nums[left];
}
int main(){
	vector<int> a = { 4,5,6,7,0,1,2 };
	findMin(a);
	return 0;
}