#include<iostream>
using namespace std;
class Day {
public:
	Day(int, int, int);
	Day(const Day&);
	Day& operator++();
	Day operator++(int);
	Day& operator--();
	Day operator--(int);
	Day& operator+=(int);
	Day& operator-=(int);
	Day operator+(int);
	Day operator-(int);
	bool operator==(const Day&);
	bool operator!=(const Day&);
	bool operator<(const Day&);
	bool operator<=(const Day&);
	bool operator>(const Day&);
	bool operator>=(const Day&);
private:
	int year;
	int mouth;
	int day;
};
Day::Day(int y, int m, int d) {
	year = y;
	mouth = m;
	day = d;
}
Day::Day(const Day& d) {
	year = d.year;
	mouth = d.mouth;
	day = d.day;
}
Day& Day::operator++() {
	*this += 1;
	return *this;
}
Day Day::operator++(int) {
	Day d(*this);
	*this += 1;
	return d;
}
Day& Day::operator--() {
	return *this -= 1;
}
Day Day::operator--(int) {
	Day d(*this);
	*this -= 1;
	return d;
}
Day& Day::operator-=(int num) {
	*this = *this + num;
	return *this;
}
Day& Day::operator+=(int num) {
	*this = *this + num;
	return *this;
}
Day Day::operator+(int num) {

}
Day Day::operator-(int num) {

}
bool Day::operator<(const Day& d) {
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
bool Day::operator==(const Day& d) {
	return year == d.year && mouth == d.mouth && day == d.day;
}
bool Day::operator>(const Day& d) {
	return !(*this <= d);
}
bool Day::operator>=(const Day& d) {
	return *this > d || *this == d;
}
bool Day::operator!=(const Day& d) {
	return !(*this == d);
}
bool Day::operator<=(const Day& d) {
	return *this < d || *this == d;
}
int main() {

	return 0;
}
