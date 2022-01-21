#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
 
// UNIX PROCESSES IN C { CODEVAULT }, video 22 - How to send a string through a pipe

int main(int argc, char **argv)
{
	int pid1 = fork();
	if (pid1 == -1)
		return 1;
	if (pid1 == 0)
	{
		sleep(3);
		printf("Finished execution (%d)\n", getpid());
		return (0);
	}
	int pid2 = fork();
	if (pid2 == -1)
		return 1;
	if (pid2 == 0)
	{
		sleep(1);
		printf("Finished execution (%d)\n", getpid());
		return (0);
	}
	int pid1_res = waitpid(pid1, NULL, 0);
	printf("Waited for %d\n", pid1_res);
	int pid2_res = waitpid(pid2, NULL, 0);
	printf("Waited for %d\n", pid2_res);
}