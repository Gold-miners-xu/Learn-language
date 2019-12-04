#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int Aliquot3(int lef, int rig) {
	if (lef > rig || lef <= 0)
		return -1;
	int sum = 0;
	int ret = 0;
	for (int i = 1; i <= rig; i++) {
		sum += i * pow(10, (int)i - 1);
		if (i >= lef && sum % 3 == 0) {
			ret++;
		}
	}
	return ret;
}
int main() {
	int lef, rig;
	scanf("%d %d", &lef, &rig);
	printf("%d", Aliquot3(lef, rig));

	return 0;

}