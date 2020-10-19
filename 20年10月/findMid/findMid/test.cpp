#include<iostream>
#include<vector>
using namespace std;
//查找第k小的元素
int find(vector<int>& nums1, vector<int>& nums2, int n) {
	if (nums1.size() == 0)
		return nums2[n - 1];
	else if (nums2.size() == 0)
		return nums1[n - 1];
	int left1 = 0, left2 = 0;
	int n1, n2;
	int mid;
	while (n > 1) {
		mid = n / 2 - 1;
		n1 = mid + left1;
		n2 = mid + left2;
		if (n1 > nums1.size() - 1) {
			n1 = nums1.size() - 1;
		}
		if (n2 > nums2.size() - 1) {
			n2 = nums2.size() - 1;
		}
		if (nums1[n1] >= nums2[n2]) {
			n -= n2 - left2 + 1;
			left2 = n2 + 1;
		}
		else {
			n -= n1 - left1 + 1;
			left1 = n1 + 1;
		}
		if (left1 == nums1.size())
			return nums2[n + left2 - 1];
		if (left2 == nums2.size())
			return nums1[n + left1 - 1];
	}
	return nums1[left1] < nums2[left2] ? nums1[left1] : nums2[left2];
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int size = nums1.size() + nums2.size();
	double ret;
	if (size % 2 == 0) {
		ret = (double)(find(nums1, nums2, size / 2) + find(nums1, nums2, size / 2 + 1)) / 2;
	}
	else
		ret = (double)find(nums1, nums2, size / 2 + 1);
	return ret;
}