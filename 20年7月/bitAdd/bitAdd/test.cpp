#include<iostream>
using namespace std;
int addAB(int A, int B) {
	// write code here
	if (B == 0)
		return A;
	while (B != 0) {
		int sum = A ^ B;
		B = (A & B) << 1;
		A = sum;
	}
	return A;
}