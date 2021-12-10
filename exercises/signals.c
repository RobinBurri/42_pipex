#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

// int main(void)
// {
// 	int pid = fork();
// 	if (pid == -1) {
// 		return (1);
// 	}
// 	if (pid == 0) {
// 		while (1) {
// 			printf("Some text goes here\n");
// 			usleep(50000);
// 		}
// 	} else {
// 		sleep(1);
// 		kill(pid, SIGKILL);
// 		wait(NULL);
// 	}
// 	return (0);
// }