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
	int err;
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0) {
		err = execlp("ping", "ping", "-c", "3", "google.con", NULL);
		if (err == -1) {
			printf("Could not find the program to execute!\n");
			return (2);
		}
	} else {
		int wstatus;
		wait(&wstatus);
		if (WIFEXITED(wstatus)) {
			int statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0) {
				printf("Success!\n");
			} else {
				printf("Failure with status code %d\n", statusCode);
			}
		}
		printf("Some post processes here, main.");
	}
	
	return (0);
}
