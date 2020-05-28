#include<iostream>
using namespace std;
void cal(int year, int day) {
	int r = 0;
	int month = 1;
	if (year % 4 == 0) {
		r = 1;
		if (year % 100 == 0) {
			r = 0;
			if (year % 400 == 0)
				r = 1;
		}
	}
	while (day > 28) {
		if (month == 2 && r == 1 && day > 29) {
			month += 1;
			day -= 29;
		}
		else if (month == 2 && r == 0) {
			month += 1;
			day -= 28;
		}
		else if ((month == 1 || month == 3 || month == 5 || month == 7
			|| month == 8 || month == 10 ) && day > 31) {
			month += 1;
			day -= 31;
		}
		else if ((month == 4 || month == 6 || month == 9 || month == 11 ) && day > 30) {
			month += 1;
			day -= 30;
		}
		else {
			break;
		}
	}
	if (day < 9 && month < 9) {
		cout << year << "-0" << month << "-0" << day << endl;
	}
	else if (day < 9) {
		cout << year << "-" << month << "-0" << day << endl;
	}
	else if (month < 9) {
		cout << year << "-0" << month << "-" << day << endl;
	}
	else {
		cout << year << "-" << month << "-" << day << endl;
	}
}
int main() {
	int year;
	int day;
	char cont;
	while (1) {
		cin >> year >> day;
		cal(year, day);
	}
	return 0;
}