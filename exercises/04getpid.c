#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

// NO VIDEO 3
// UNIX PROCESSES IN C { CODEVAULT }, video 4 - getpid() && getppid() function
int main()
{
	int id = fork();
	if (id == 0)
		sleep(1);
	// Wait return the process id it waited for if needed
	wait(NULL); //Will make the parent wait for children to finish even if not checking (id != 0)
	printf("Current ID :%d, Parent ID : %d\n", getpid(), getppid());

	return (0);
}