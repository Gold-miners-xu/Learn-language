#include<iostream>
using namespace std;
int main() {
	int num;
	while (cin >> num) {
		int max = 0;
		int count = 0;
		while (num != 0) {
			if (num % 2 == 1)
				count++;
			else
				count = 0;
			if (count > max)
				max = count;
			if (num == 1) {
				///max = (max > (count + 1) ? max : (count + 1));
				break;
			}
			num /= 2;
		}
		cout << max << endl;
	}
	return 0;
}