#include<iostream>

int main() {
	const char p = 'a';
	char* x = &p;
	*x = 'b';
	std::cout << p << std::endl;
	return 0;
}
int add(int a, int b, int c = 0);
int add(int a, int b);
add(10, 20);