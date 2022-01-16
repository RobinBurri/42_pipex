#include <unistd.h>
#include <stdio.h>

// UNIX PROCESSES IN C { CODEVAULT }, video 1 - fork() function
int main()
{
	int pid;
	pid = fork();
	if (pid != 0)
	 	fork();
	if (pid == 0)
		printf("hello, from child!\n");
	else
		printf("hello, from parent!\n");
	return 0;
}