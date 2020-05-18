#include<stdio.h>
#include<sys/wait.h>                   
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

int get_input(char* buf) {
	memset(buf, 0x00, sizeof(buf));
	if (scanf("%[^\n]%*c", buf) != 1) {
		int c;
		do
			c = getchar();
		while (c != '\n');
	}
	return strlen(buf);
}

void do_action(int argc, char* argv[]) {
	pid_t pid;
	if ((pid = fork()) == -1) {
		printf("当前系统异常,正在在维护中...\n");
		return;
	}
	if (pid == 0) {
		execvp(argv[0], argv);
		printf("%s : command not found\n", argv[0]);
		exit(1);
	}
	int status;
	waitpid(pid, &status, 0);
}
void do_parse(char* buf) {
	int argc = 0;
	char* argv[10];
#define OUT 0
#define IN 1
	int status = OUT;
	int i;
	for (i = 0; buf[i] != '\0'; i++) {
		if (status == OUT && buf[i] != ' ') {
			argv[argc++] = buf + i;
			status = IN;
		}
		else if (buf[i] == ' ') {
			status = OUT;
			buf[i] = '\0';
		}
	}
	argv[argc] = NULL;
	do_action(argc, argv);
}

int main() {
	char buf[512];
	while (1) {
		printf("[along shell]#");
		if (get_input(buf) == 0)
			continue;
		do_parse(buf);
}
