#include<iostream>
#include<cmath>
using namespace std;
bool pre(int num) {
	int sum = 1;
	for (int i = 2; i < sqrt(num); i++) {
		if (num % i == 0) {
			sum += i;
			sum += (num / i);
		}
	}
	if (sum == num)
		return true;
	return false;
}
int main() {
	int n;
	while (cin >> n) {
		int count = 0;
		for (int i = 2; i < n; i++) {
			if (pre(i))
				count++;
		}
		cout << count << endl;
	}
	return 0;
}