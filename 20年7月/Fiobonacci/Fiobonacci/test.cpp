#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a = 0, b = 1;
	while (a < n && b < n) {
		a = a + b;
		if (a >= n || b >= n)
			break;
		b = b + a;
	}
	if (((a < b ? b : a) - n) < (n - (a < b ? a : b)))
		cout << (a < b ? b : a) - n << endl;
	else
		cout << n - (a < b ? a : b) << endl;
	return 0;
}