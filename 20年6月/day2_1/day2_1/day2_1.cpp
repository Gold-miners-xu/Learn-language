#include<iostream>

using namespace std;
int main() {
	int num;
	cin >> num;
	int* a = new int[num];
	int rit = 0;
	for (int i = 0; i < num; i++) {
		cin >> *(a + i);
	}
	for (int i = 1; i < num; i++) {
		if (a[i - 1] == a[i]) {
			continue;
		}

		else if (a[i - 1] < a[i]) {
			while (a[i - 1] <= a[i]) {
				i++;
			}
			rit++;
		}
		else {
			while (a[i - 1] >= a[i]) {
				i++;
			}
			rit++;
		}
		if (i == num - 1)
			rit++;
	}
	cout << rit << endl;
	return 0;
}