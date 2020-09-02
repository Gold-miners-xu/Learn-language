#include<iostream>
#include<algorithm>
#include<vector>
#include <functional>
using namespace std;
class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		partial_sort(arr.begin(), arr.begin() + k, arr.end());
		arr.erase(arr.begin() + k, arr.end());
		return arr;
	}
};
void test1() {
	// �Ҹ�������ǰ4����С��Ԫ��, Ԫ�����մ洢��v1��ǰ4��λ��
	vector<int> v1{ 4, 1, 8, 0, 5, 9, 3, 7, 2, 6 };
	partial_sort(v1.begin(), v1.begin() + 4, v1.end());
	// �Ҹ�������ǰ4������Ԫ��, Ԫ�����մ洢��v1��ǰ4��λ��
	vector<int> v2{ 4, 1, 8, 0, 5, 9, 3, 7, 2, 6 };
	partial_sort(v2.begin(), v2.begin() + 4, v2.end(), greater<int>());
	for (int i = 0;i < 4;i++)
		cout << v1[i] << " ";
	cout << endl;
	for (int j = 0; j < 4; j++)
		cout << v2[j] << " ";

}
int main() {
	test1();
	return 0;
}