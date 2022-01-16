#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

// In the case of a terminated child, performing a wait allows the system to release the resources associated with the child
// if a wait is not performed, then the terminated child remains in a "zombie" state
int main(void)
{
	pid_t	id;
	int 	n;
	int 	i;

	id = fork();
	if (id == 0)
		n = 1;
	else
		n = 6;

	// if (id != 0)			// if we are in the main process () => optional because by default wait until one of its children terminates
		wait(0);			// wait the child process to finish
	
	i = n;
	while (i < n + 5)
	{
		printf("%d ", i);
		i++;
	}
	if(id != 0)
		printf("\n");
	
	return (0);
}
