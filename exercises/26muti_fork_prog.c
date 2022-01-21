#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>

// UNIX PROCESSES IN C { CODEVAULT }, video 5 - fork() multiple time practical exemple
#define PROCESS_NUM 3

int main(int argc, char **argv)
{
	int pipes[PROCESS_NUM + 1][2];
	int pids[PROCESS_NUM];

	
	for (int i = 0; i < PROCESS_NUM + 1; i++)
	{
		if (pipe(pipes[i]) == -1){
			printf("Error with creating pipe\n");
			return (1);
		}
	}
	// printf("Outside: %d, parent: %d\n", getpid(), getppid());

	// Creating multiple child from the same parent
	for (int i = 0; i <PROCESS_NUM; i++)
	{
		pids[i] = fork();
		if (pids[i] == -1) {
			printf("Error with creating process\n");
			return (2);
		}
		// printf("Inside: %d, parent: %d -- id: %d\n", getpid(), getppid(), i);
		// printf("finished loop number: %d\n", i);

		if (pids[i] == 0) {
			// Child process
			// printf("Inside: %d, parent: %d\n", getpid(), getppid());
			for (int j = 0; j < PROCESS_NUM + 1; j++){
				// close unused read ends of pipes
				if (i != j) {
					close(pipes[j][0]);
				}
				// close unused write ends of pipes
				if (i + 1 != j) {
					close(pipes[j][1]);
				}
			}
			int x;
			if (read(pipes[i][0], &x, sizeof(int)) == -1) {
				printf("Error at reading\n");
				return 3;
			}
			x *= 2;
			if (write(pipes[i + 1][1], &x, sizeof(int)) == -1) {
				printf("Error writing\n");
				return 4;
			}
			close(pipes[i][0]);
			close(pipes[i + 1][1]);
			return 0;
		}
	}
	// Main process only
	int y = 10;
	printf("y = %d\n", y);
	if (write(pipes[0][1], &y, sizeof(int)) == -1) {
		printf("Error writing\n");
		return 4;
	}
	if (read(pipes[PROCESS_NUM][0], &y, sizeof(int)) == -1) {
		printf("Error at reading\n");
		return 3;
	}
	close(pipes[0][1]);
	close(pipes[PROCESS_NUM][0]);
	printf("y = %d\n", y);

	for (int i = 0; i <PROCESS_NUM; i++)
	{
		wait(NULL);
	}
	return (0);
}
