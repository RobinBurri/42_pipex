#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
 
// UNIX PROCESSES IN C { CODEVAULT }, video 21 - How to send an array through a pipe

// 2 processes
// 1> Child process should generate random numbers and send them to the parent
//2> Parent is going to sum all the numbers and print the result

int main(int argc, char **argv)
{
	int fd1[2]; // C to P, 0 = read, 1 = write
	srand(time(NULL));

	if (pipe(fd1) == -1)
		return (-1);
	
	int pid = fork();
	if (pid == -1)
		return (-1);
	
	wait(NULL);
	if (pid == 0)
	{
		// CHILD
		int n;
		printf("how many ints?: ");
		scanf("%d", &n);
		close(fd1[0]);
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 100;
			printf("gener: %d\n", arr[i]);
		}
		// int fd = open(fd1[1], O_RDONLY);
		write(fd1[1], &n, sizeof(int));
		write(fd1[1], &arr, sizeof(arr));
		close(fd1[1]);

	} else {
		// PARENT
		close(fd1[1]);
		int n;
		read(fd1[0], &n, sizeof(int));
		int arr[n];
		// int fd = open(fd1[0], O_WRONLY);
		read(fd1[0], &arr, sizeof(arr));
		close(fd1[0]);
		int sum;
		for (int i = 0; i < n; i++)
			sum += arr[i];
		printf("sum: %d\n", sum);
	}		
	return (0);
}