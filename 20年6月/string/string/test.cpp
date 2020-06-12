#include<string>
#include<iostream>
using namespace std;

void test1() {
	string s1 = "abc";
	string s2 = "123";
	string s3 = s1 + s2;
	for (string::iterator it = s3.begin(); it != s3.end(); it++) {
		cout << *it << " ";
	}
	cout << s3.size() << " " << s3.length() << endl;
	s3.resize(7, 'd');
	cout << s3 << endl;
	cout << s3.capacity() << endl;
	s3.reserve(50);
	cout << s3.capacity() << endl;
	s3.clear();
	cout << s3.capacity() << " " << s3.size() << endl;

}
int main() {
	test1();
	return 0;
}