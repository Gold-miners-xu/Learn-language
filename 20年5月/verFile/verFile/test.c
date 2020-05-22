#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main() {
	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test.txt", O_RDWR);
	char buf1[10 + 1];
	char buf2[10 + 1];
	
	read(f1, buf1, 10);
	read(f2, buf2, 10);
	printf("buf = ", buf1);
	printf("buf = ", buf2);
	return 0;
}