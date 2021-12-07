#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


// Executing commands in C
// int main(void)
// {
// 	//execl("/sbin/ping", "/sbin/ping", "google.com", NULL);
// 	// OR
// 	//char *arr[] = { "ping", "google.com", NULL};
// 	//execvp("ping", arr);
// 	//OR
// 	execlp("ping", "ping", "google.com", NULL);
// 	return (0);
// }


// Executing commands in child process while the main waits
int main(void)
{
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
	}
	else
	{
		wait(NULL);
		printf("Some post processes here, main.");
	}
	
	return (0);
}
