#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

// UNIX PROCESSES IN C { CODEVAULT }, video 11 - Executing commands in C
// UNIX PROCESSES IN C { CODEVAULT }, video 12 - gettting exit status in C

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

// EXEC must be done in the child process not the parent as it replace everything and it can wait for child no more
// Executing commands in child process while the main waits
int main(void)
{
	int err;
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0) {
		err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
		// execlp will replace all the code under if succeed and return -1 if fail to execute the command
		printf("%d\n", err);
		if (err == -1) {
			printf("Could not find the program to execute!\n");
			return (2);
		}
	} else {
		// Parent process
		int wstatus;
		wait(&wstatus);
		if (WIFEXITED(wstatus)) { // if child process finished normally WIFEXITED == 0
			int statusCode = WEXITSTATUS(wstatus); // else
			if (statusCode != 0)
				printf("Failure with status code %d\n", statusCode);
		}
		//Code Continue
		printf("Some post processes here, main.\n");
	}
	
	return (0);
}
