#include<stdio.h>
#include<string.h>
int IsEqual(char* s1, char* s2) {
	if (strlen(s1) == strlen(s2)) {
		int i = 0, j = strlen(s1) - 1;
		while (i < strlen(s1)) {
			if (s1[i] != s2[j])
				break;
			i++;
			j--;
		}
		if (i == strlen(s1))
			return 1;
	}
	return 0;
}
//判断一个字符串是否为另外一个字符串旋转之后的字符串
void Rotating(int k, char* s) {
	if (k > strlen(s) || k < 0) {
		printf("false");
	}
	int left = 0, rit = strlen(s) - 1;
	while (left < rit) {
		int tmp = s[left];
		s[left] = s[rit];
		s[rit] = tmp;
		left++;
		rit--;
	}
	left = 0;
	rit = strlen(s) - k - 1;
	while (left < rit) {
		int tmp = s[left];
		s[left] = s[rit];
		s[rit] = tmp;
		left++;
		rit--;
	}
	left = strlen(s) - k;
	rit = strlen(s) - 1;
	while (left < rit) {
		int tmp = s[left];
		s[left] = s[rit];
		s[rit] = tmp;
		left++;
		rit--;
	}
}
//左旋字符串中的k个字符
int MatrixFind(int** a, int k,int x,int y) {
	//x*y矩阵查找
	int i = (y-1) / 2;
	int left = 0, rit = (y-1);
	while (i > 0) {
		if (a[0][i] < k) {
			left = i;
			i = (rit - left) / 2;
		}
		else if (a[0][i] > k) {
			rit = i;
			i = (rit - left) / 2;
		}
		else
			return 1;
		if (i == 0) {
			int j = (x-1)/ 2;
			int on = 0, down = (x-1);
			while (j > 0) {
				if (a[left][j] < k) {
					on = j;
					j = (down - on) / 2;

				}
				else if (a[left][j] > k) {
					down = j;
					j = (down - on) / 2;
				}
				else
					return 1;
				if (j == x - 1)
					return 0;
			}
		}
	}
	return 0;
}
//矩阵查找数字
int main() {
//	char s[] = "abcd";
//	char x[] = "dcba";
//	printf("%d", IsEqual(s, x));
//	char s[] = "abcd";
//	Rotating(3, s);
	int a[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	printf("%d", MatrixFind(a, 5, 3, 3));
//	printf("%c%c%c%c", s[0], s[1], s[2], s[3]);
	return 0;
}
