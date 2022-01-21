#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>



// UNIX PROCESSES IN C { CODEVAULT }, video 13 - How to execute another program in C

int main(int argc, char **argv)
{
	int pid;
	pid = fork();
	if (pid == 0)
	{
		//EXECL with the full path to the command and the NULL pointer at the end // L for list
		execl("/sbin/ping", "/sbin/ping","-c", "3", "google.com", NULL);
	}
	wait(NULL);
	printf("\n\033[0;31mEXECL END\033[0m\n\n");


	pid = fork();
	if (pid == 0)
	{
		//EXECLP with the command and the NULL pointer at the end // L for list
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
	}
	wait(NULL);
	printf("\n\033[0;31mEXECLP END\033[0m\n\n");


	pid = fork();
	if (pid == 0)
	{
		char *arr[] = {
			"ping",
			"google.com",
			"-c",
			"3",
			NULL
		};
		//EXECL with the full path to the command and the NULL pointer at the end // V for vector
		execvp("/sbin/ping", arr);
	}
	wait(NULL);
	printf("\n\033[0;31mEXECVP END\033[0m\n\n");


	
	pid = fork();
	if (pid == 0)
	{
		char *arr[] = {
			"ping",
			"google.com",
			"-c",
			"3",
			NULL
		};
		char *env[] = {
			"TEST=environment variable",
			NULL
		};
		//EXECL with the full path to the command and the NULL pointer at the end // V for vector
		execve("/sbin/ping", arr, env);
	}
	wait(NULL);
	printf("\n\033[0;31mEXECVE END\033[0m\n\n");

	return (0);
}