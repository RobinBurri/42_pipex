#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

// UNIX PROCESSES IN C { CODEVAULT }, video 2 - wait() function
int main()
{
	int id;
	id = fork();
	int n;
	if (id == 0)
	 	n = 1;
	else
		n = 6;
	if (id != 0) // if it's not child => wait
		wait(NULL);
	for (int i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	if (id != 0)
		printf("\n");
	
	return 0;
}

// fflush() => flushes printf buffer every loop