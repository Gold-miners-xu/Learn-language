#include<stdio.h>
#include<unistd.h>

int main(void) {
	pid_t pid = fork();

	if (pid == 0) {
		printf("child");
	}
	else {
		printf("parent");
	}
	return 0;
}


