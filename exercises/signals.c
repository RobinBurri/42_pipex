#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

int main(void)
{
	int pid = fork();
	if (pid == -1) {
		return (1);
	}
	if (pid == 0) {
		while (1) {
			printf("Some text goes here\n");
			usleep(50000);
		}
	} else {
		kill(pid, SIGSTOP);

		int t;
		do {
			printf("Time in sec for exeution:");
			scanf("%d", &t);
			if (t > 0) {
				kill(pid, SIGCONT);
				sleep(t);
				kill(pid, SIGSTOP);
			}
		} while (t > 0);
		
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return (0);
}