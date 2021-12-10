#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main(void)
{
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		int file = open("pingResult.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
		{
			return (2);
		}
		// int file2 is useless because we know it's 1
		// dup2(new_output, oldd_output)
		int file2 = dup2(file, STDOUT_FILENO);
		close(file);
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
	}
	else
	{
		wait(NULL);
		printf("Some post processes here, main.");
	}

	return (0);
}
