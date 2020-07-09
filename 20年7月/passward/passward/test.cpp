#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	while (cin >> str) {
		int len = str.length();
		int letter = 0;
		int bigLetter = 0;
		int num = 0;
		int symbol = 0;
		int rit = 0;
		for (int i = 0; i < len; i++) {
			if (str[i] <= '9' && str[i] >= '0')
				num++;
			else if (str[i] <= 'z' && str[i] >= 'a')
				letter++;
			else if (str[i] <= 'Z' && str[i] >= 'A')
				bigLetter++;
			else
				symbol++;
		}
		if (len <= 4)
			rit += 5;
		else if (len <= 7)
			rit += 10;
		else
			rit += 25;
		if (letter != 0 && bigLetter != 0)
			rit += 20;
		else if (letter != 0 || bigLetter != 0)
			rit += 10;
		if (num > 1)
			rit += 20;
		else if (num == 1)
			rit += 10;
		if (symbol > 1)
			rit += 25;
		else if (symbol == 1)
			rit += 10;
		if (num != 0 && letter != 0 && bigLetter != 0 && symbol != 0)
			rit += 5;
		else if ((letter == 0 || bigLetter == 0) && num != 0 && symbol != 0)
			rit += 3;
		else if (symbol == 0)
			rit += 2;
		if (rit >= 90)
			cout << "VERY_SECURE" << endl;
		else if (rit >= 80)
			cout << "SECURE" << endl;
		else if (rit >= 70)
			cout << "VERY_STRONG" << endl;
		else if (rit >= 60)
			cout << "STRONG" << endl;
		else if (rit >= 50)
			cout << "AVERAGE" << endl;
		else if (rit >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}