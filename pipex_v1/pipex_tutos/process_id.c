#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(void)
{
	pid_t	id;
	int		res;

	id = fork();
	res = wait(NULL); 	// Wait returns the process ID of the terminated child
	printf("Child process forked id : %d | Current process : %d | Parent id : %d\n", id, getpid(), getppid());
	
	if (res == -1)		// or, if no child (on failure), -1 is returned
		printf("No children to wait for\n");	// child process
	else
		printf("%d finished execution\n", res);	// main process

	return (0);
}
// Upon successful completion, fork() returns a value of 0 to the child process 
// and returns the process ID of the child process to the parent process.

// Children processes must terminate before parent process in order to keep their parent process id
// and to not be a zombie process
