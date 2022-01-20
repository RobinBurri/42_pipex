#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

// UNIX PROCESSES IN C { CODEVAULT }, video 16 - 17 signals


// YOU DON'T NEED TO CODE IN THE CHILD PROCESS
// YOU CAN JUST SEND HIM SIGNALS
int main(int argc, char **argv)
{
	int pid = fork();
	int pidmain = getpid();

	printf("pidmain: %d\npid: %d\n", pidmain, pid);
	if (pid == -1)
		return 1;
	
	if (pid == 0)
	{
		while (1)
		{
			printf("Some text goes here\n");
			usleep(500000);
		}
	}	else 	{
		kill(pid, SIGSTOP);
		unsigned int t = 1;
		
		while (t > 0)
		{
			printf("Time in sec for exectution: \n");	
			scanf("%d", &t);
			kill(pid, SIGCONT);
			sleep(t);
			kill(pid, SIGSTOP);
		}
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return (0);
}