#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
	int num = 0;
	size_t count = 1;
	size_t max = 0;
	if (numbers.size() == 1)
		return numbers[0];
	sort(numbers.begin(), numbers.end());
	for (size_t i = 1; i < numbers.size(); i++) {
		while (numbers[i - 1] == numbers[i]) {
			count++;
			i++;
		}
		if (count > max) {
			num = numbers[i - 1];
			max = count;
		}
		count = 1;
	}
	if (max > numbers.size() / 2)
		return num;
	return 0;
}

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(2);
	MoreThanHalfNum_Solution(v);
	return 0;
}