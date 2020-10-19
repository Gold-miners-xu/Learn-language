#include<iostream>
using namespace std;
class Date {
public:
	//Date构造
	Date(int, int, int);
	//Date拷贝构造
	Date(const Date&);
	//前置++运算符重载
	Date& operator++();
	//后置++运算符重载
	Date operator++(int);
	//前置--运算符重载
	Date& operator--();
	//后置--运算符重载
	Date operator--(int);
	//+=运算符重载
	Date& operator+=(int);
	//-=运算符重载
	Date& operator-=(int);
	//+法运算符重载
	Date operator+(int);
	//-法运算符重载
	Date operator-(int);
	//==运算符重载
	bool operator==(const Date&);
	//!=运算符重载
	bool operator!=(const Date&);
	//<运算符重载
	bool operator<(const Date&);
	//<=运算符重载
	bool operator<=(const Date&);
	//>运算符重载
	bool operator>(const Date&);
	//>=运算符重载
	bool operator>=(const Date&);
	//打印函数
	void Print() const;
private:
	bool isLeapYear() {
		if (year % 4 == 0 && year % 100 != 0)
			return true;
		if (year % 400 == 0)
			return true;
		return false;
	}
	static int day_size[12];
	int year;
	int mouth;
	int day;
};
int Date::day_size[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
Date::Date(int y, int m, int d)
{
	year = y;
	mouth = m;
	day = d;
}
Date::Date(const Date& d) {
	year = d.year;
	mouth = d.mouth;
	day = d.day;
}
Date& Date::operator++() {
	*this += 1;
	return *this;
}
Date Date::operator++(int) {
	Date d(*this);
	*this += 1;
	return d;
}
Date& Date::operator--() {
	return *this -= 1;
}
Date Date::operator--(int) {
	Date d(*this);
	*this -= 1;
	return d;
}
Date& Date::operator-=(int num) {
	*this = *this - num;
	return *this;
}
Date& Date::operator+=(int num) {
	*this = *this + num;
	return *this;
}
Date Date::operator+(int num) {
	Date ret(*this);
	while (num > 0) {
		if (ret.mouth == 2 && ret.isLeapYear()) {
			if (num > day_size[1] - ret.day + 1) {
				num -= (day_size[ret.mouth - 1] - ret.day) + 1;
				ret.day = 1;
				ret.mouth++;
				continue;
			}
			else {
				ret.day += num;
				num = 0;
				break;
			}
		}
		if (num > day_size[ret.mouth - 1] - ret.day) {			
			num -= (day_size[ret.mouth - 1] - ret.day) + 1;
			ret.day = 1;
			ret.mouth++;
			
		}
		else {
			ret.day += num;
			break;
		}
		if (ret.mouth > 12) {
			ret.mouth -= 12;
			ret.year++;
		}
	}
	return ret;
}
Date Date::operator-(int num) {
	Date ret(*this);
	while (num > 0) {
		if (ret.mouth == 3 && ret.isLeapYear()) {
			if (num >= ret.day) {
				ret.mouth--;
				num -= ret.day;
				ret.day = day_size[1] + 1;
				continue;
			}
			else {
				ret.day -= num;
				break;
			}
		}
		if (num >= ret.day) {
			ret.mouth--;
			num -= ret.day;
			if (ret.mouth == 0)
				ret.day = day_size[11];
			else
				ret.day = day_size[ret.mouth - 1];
		}
		else {
			ret.day -= num;
			break;
		}
		if (ret.mouth <= 0) {
			ret.mouth += 12;
			ret.year--;
		}
	}
	return ret;
}
bool Date::operator<(const Date& d) {
	if (year < d.year) {
		return true;
	}
	else if (year == d.year) {
		if (mouth < d.mouth) {
			return true;
		}
		else if (mouth == d.mouth) {
			if (day < d.day) {
				return true;
			}
		}
	}
	return false;
}
bool Date::operator==(const Date& d) {
	return year == d.year && mouth == d.mouth && day == d.day;
}
bool Date::operator>(const Date& d) {
	return !(*this <= d);
}
bool Date::operator>=(const Date& d) {
	return *this > d || *this == d;
}
bool Date::operator!=(const Date& d) {
	return !(*this == d);
}
bool Date::operator<=(const Date& d) {
	return *this < d || *this == d;
}
void Date::Print()const {
	cout << year << " " << mouth << " "  << day << endl;
}
int main() {
	Date day1(2020, 10, 19);
	day1.Print();
	day1 -= 999;
	day1++;
	day1.Print();
	return 0;
}
