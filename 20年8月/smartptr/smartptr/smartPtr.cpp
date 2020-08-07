#include<memory>
#include<iostream>
using namespace std;
template <class T>
class smtPtr {
public:
	smtPtr(T* ptr)
		:_ptr(ptr)
	{}
	~smtPtr() {
		if (_ptr)
			delete _ptr;
	}
	T* operator->() {
		return _ptr;
	}
	T& operator{
		return *_ptr;
	}
private:
	T* _ptr;
};
void test1() {
	auto_ptr<int> ap1(new int(0));
	cout << *ap1 << endl;
	auto_ptr<int> ap2 = ap1;
	cout << *ap1 << endl;
}
void test2() {
	unique_ptr<int> up1(new int(0));
	cout << *up1 << endl;
	unique_ptr<int> up2;
	//up2 = up1;
}
void test() {
	shared_ptr<int> sp(new int(0));
	weak_ptr<int> wp1 = sp;
	weak_ptr<int> wp2 = wp1;
	weak_ptr<int> wp3(new int(0));
}
int main() {
	test1();
	return 0;
}