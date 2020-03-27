#include<stdio.h>
#include<stdlib.h>
int* distributeCandies(int candies, int num_people, int* returnSize) {
	int n = 1;
	*returnSize = num_people;
	int* people = (int*)calloc(num_people, sizeof(int));
	for (int i = 0; candies > 0; i++) {
		if (i == num_people) {
			i = 0;
		}
		if (candies >= n) {
			candies -= n;
			people[i] += n;
			n++;
		}
		else {
			people[i] += candies;
			candies = 0;
			break;
		}
	}
	return people;
}
int main() {
	int a;
	distributeCandies(7, 4, &a);
	return 0;
}