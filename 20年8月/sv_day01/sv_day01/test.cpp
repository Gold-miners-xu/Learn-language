#include<iostream>
#include<vector>
using namespace std;
bool test(vector<vector<int>> arr,int num) {
	int i = 0, j = arr[0].size() - 1;
	while( i < arr.size() && j >= 0 ) {
		if (arr[i][j] > num)
			j--;
		else if (arr[i][j] < num)
			i++;
		else
			return true;
	}
	return false;
}
int main() {
	//int i = 10, j = 10, k = 3;
	//k *= i + j;
	/*int a[] = { 2,4,6,8,10,12,14,16,18,20,22,24 }, * q[4], k;
	for (k = 0; k < 4; k++) { 
		q[k] = &a[k * 3]; 
	}
	printf("%d\n", q[3][1]);*/
	/*int i, j, a = 0; 
	for (i = 0; i < 2; i++) { 
		for (j = 0; j < 4; j++) { 
			if (j % 2) break; 
			a++; 
		}
		a++; 
	}
	printf("%d\n", a);*/
	vector<vector<int>> arr;
	test(arr,10);
	return 0;
}