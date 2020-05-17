#include<iostream>
using namespace std;

int& test() {
	int a = 10;
	int& b = a;
	return b;
}
void test2() {
	int a[] = { 1,2,3,4,5 };
	for (auto i : a)
		cout << i << " " << endl;
}
int main() {
	//int& c= test();
	//cout << c << " " << &c << endl;
	test2();
	return 0;
}