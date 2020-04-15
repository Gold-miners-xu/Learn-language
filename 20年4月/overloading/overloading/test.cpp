#include<iostream>
using namespace std;

class myData {
	friend ostream& operator<<(ostream& cout, myData my);
public:
	myData() {
		m_Data = 10;
	}
	//Ç°ÖÃ
	myData& operator--() {
		m_Data--;
		return *this;
	}
	//ºóÖÃ
	myData operator--(int) {
		myData tmp = *this;
		m_Data--;
		return tmp;
	}


private:
	int m_Data;
};
ostream& operator<<(ostream& cout, myData my) {
	cout << my.m_Data;
	return cout;
}

int main() {
	myData my;
	cout << --my << endl;
	cout << my-- << endl;
	cout << my << endl;
	return 0;
}
