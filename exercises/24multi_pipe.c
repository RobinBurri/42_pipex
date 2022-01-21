#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
 
// UNIX PROCESSES IN C { CODEVAULT }, video 24 - Working with multiple pipes

// main x = 1 => p1 x = x + 2 => p2 x = x + 2 => main recieve 5
#define PIPES_NUM 3

int main()
{
	int pfd[PIPES_NUM][2];
	for (int i = 0; i < PIPES_NUM; i++)
	{
		if (pipe(pfd[i]) == -1)
			return (1);
	}
	int pid1 = fork();
	if (pid1 == -1)
		return (2);
	if (pid1 == 0)
	{
		int x;
		close(pfd[0][1]);
		close(pfd[1][0]);
		close(pfd[2][0]);
		close(pfd[2][1]);
		read(pfd[0][0], &x, sizeof(int));
		x += 2;
		write(pfd[1][1], &x, sizeof(int));
		close(pfd[0][0]);
		close(pfd[1][1]);
		return (0);
	}
	int pid2 = fork();
	if (pid2 == -1)
		return (2);
	if (pid2 == 0)
	{
		int x;
		close(pfd[0][0]);
		close(pfd[0][1]);
		close(pfd[1][1]);
		close(pfd[2][0]);
		read(pfd[1][0], &x, sizeof(int));
		x += 2;
		write(pfd[2][1], &x, sizeof(int));
		close(pfd[1][0]);
		close(pfd[2][1]);
		return (0);
	}
	int x = 1;
	printf("%d\n", x);
	close(pfd[0][0]);
	close(pfd[1][1]);
	close(pfd[1][0]);
	close(pfd[2][1]);
	write(pfd[0][1], &x, sizeof(int));
	read(pfd[2][0], &x, sizeof(int));
	printf("%d\n", x);
	close(pfd[0][1]);
	close(pfd[2][0]);
	wait(NULL);
	wait(NULL);

	return (0);
}