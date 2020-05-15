#define _GNU_SOURCE
#include<stdio.h>
#include<sched.h>
#include<unistd.h>
#include<stdlib.h>
int main() {
	pid_t pid;
	if ((pid = fork()) == 0) {
		cpu_set_t cpu_affinity;
		CPU_ZERO(&cpu_affinity);
		CPU_SET(0, &cpu_affinity);
		sched_setaffinity(0, sizeof(cpu_set_t), &cpu_affinity);
		while (1) {
			printf("child\n");
		}
	}
	else {
		cpu_set cpu_affinity;
		CPU_ZERO(&cpu_affinity);
		CPU_SET(1, &cpu_affinity);
		sched_setaffinity(0, sizeof(cpu_set_t), &cpu_affinity);
		while (1) {
			printf("parent\n");
		}
	}
}