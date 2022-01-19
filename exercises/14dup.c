#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

// UNIX PROCESSES IN C { CODEVAULT }, video 14 - Redirecting stdout in C

int main(void)
{
	int err;
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0) {
		int fd = open("pingResult.txt", O_WRONLY | O_CREAT, 0777);
		if (fd == -1)
			return (1);
		// fd (maybe 3) point to "pingResult.txt" || dup2() will redirect stdout to 3 (pingResult.txt)
		dup2(fd, STDOUT_FILENO);
		close(fd); // no need to have to fd pointing to "pingResult.txt" (1 & fd); 
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
		// int fd = open("mainResult.txt", O_WRONLY | O_CREAT, 0777);
		// dup2(fd, STDOUT_FILENO);
		// close(fd);
		printf("Some post processes here, main.\n");
	}
	
	return (0);
}