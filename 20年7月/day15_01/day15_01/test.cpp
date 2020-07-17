#include<iostream>
using namespace std;
int main() {
	int num;
	while (cin >> num) {
		int count = 0;
		while (num >= 1) {
			if (num == 1) {
				count++;
				break;
			}
			if (num % 2 != 0)
				count++;
			num /= 2;
		}
		cout << count << endl;
	}
	return 0;
}