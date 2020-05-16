#include<stdio.h>     
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int mysystem(const char* cmd) {
	pid_t pid;
	if ((pid = fork()) == -1)
		exit(127);
	if (pid == 0) {
		if (execlp("/bin/sh", "/bin/sh", "-c", cmd, NULL) == -1) {
			exit(1);
		}
	}
	int status;
	while (waitpid(pid, &status, WNOHANG) != pid)
		;
	if (WIFEXITED(status)) {
		return WEXITSTATUS(status);
	}
	return -1;
}
int main(void) {
	printf("before system\n");
	mysystem("ls -l");
	printf("after system\n");
}