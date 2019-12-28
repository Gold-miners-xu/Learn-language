#include<stdio.h>
bool lemonadeChange(int* bills, int billsSize) {
	int i = 0;
	int fiv = 0;
	int ten = 0;
	while (i < billsSize) {
		if (bills[i] == 5)
			fiv++;
		if (bills[i] == 10) {
			ten++;
			fiv--;
		}
		if (bills[i] == 20) {
			if (ten > 0) {
				ten--;
				fiv--;
			}
			else {
				fiv -= 3;
			}
		}
		if (fiv < 0) {
			return false;
		}
		i++;
	}
	return true;
}
int main() {
	return 0;
}