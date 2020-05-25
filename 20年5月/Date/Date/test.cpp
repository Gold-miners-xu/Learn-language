#include<iostream>
using namespace std;
class Date
{
public:
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	Date(int y = 2020, int m = 1, int d = 1) {
		_year = y;
		_month = m;
		_day = d;
	}
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;

	}
	~Date() {

	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year; // Äê
	int _month; // ÔÂ
	int _day; // ÈÕ
};
int main()
{
	Date d1, d2;
	d1.SetDate(2018, 5, 1);
	d2.SetDate(2018, 7, 1);
	d1.Display();
	d2.Display();
	return 0;
}