#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int num) {
	if (num <= 3)
		return true;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}
int main() {
	int num;
	while (cin >> num) {
		int rit = num / 2;
		while (!(isPrime(rit) && isPrime(num - rit))) {
			rit--;
		}
		cout << rit << endl;
		cout << num - rit << endl;
	}
	return 0;
}