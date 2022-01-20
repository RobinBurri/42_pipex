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
	int fd[2];

	if (pipe(fd) == -1)
		return (1);

	int pid = fork();
	if (pid < 0)
		return (2);

	if (pid == 0)
	{
		//CHILD
		close(fd[0]);
		char str[200];
		printf("Input String: ");
		fgets(str, 200, stdin);

		//remove the \n at the end off the string
		str[strlen(str) -1] = 0;
		int strl = strlen(str) + 1;
		if (write(fd[1], &strl, sizeof(int)) < 0)
			return (5);
		int check = write(fd[1], str, sizeof(char) * strl);
		if (check < 0)
			return (6);
		close(fd[1]);
	}	else	{
		// PARENT
		close(fd[1]);
		int strl;
		read(fd[0], &strl, sizeof(int));
		char str[strl];
		read(fd[0], str, sizeof(char) * strl);
		close(fd[0]);
		printf("%s\n", str);
		wait(NULL);
	}
	return (0);
}