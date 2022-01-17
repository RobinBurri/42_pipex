#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

// UNIX PROCESSES IN C { CODEVAULT }, video 6 && 7 - pipe() && practical use case 
//COMMUNICATING BETWEEN PROCESSES

//  int main()
// {
// 	int fd[2];
// 	// fd[0] - read
// 	// fd[1] - write
// 	if (pipe(fd) == -1)
// 	{
// 		printf("An error occured with openig the pipe\n");
// 		return (1);
// 	}
// 	int id = fork();
// 	if (id == 0)
// 	{
// 		close(fd[0]); //we don't use the read in this process
// 		int x;
// 		printf("Input a number: ");
// 		scanf("%d", &x);
// 		if (write(fd[1], &x, sizeof(int)) == - 1) {
// 			printf("An error occured with writing to the pipe\n");
// 			return (2);
// 		}
// 		close(fd[1]); 
// 	}
// 	else 
// 	{
// 		close(fd[1]);
// 		int y;
// 		read(fd[0], &y, sizeof(int));
// 		if (close(fd[0]) == -1) {
// 			printf("An error occured with closing the pipe\n");
// 			return (3);
// 		}
// 		printf("Got from child process: %d\n" , y);
// 	}
// 	return (0);
// }


//PRACTICAL USE FOR FORK AND PIPE

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int arrSize = sizeof(arr) / sizeof(int);
	int start, end;
	int fd[2];
	if (pipe(fd) == -1) {
		return (1);
	}
	int id = fork();
	if (id == -1) {
		return 2;
	}
	if (id == 0) {
		start = 0;
		end = (arrSize / 2);
	} else {
		start = arrSize / 2;
		end = arrSize;
	}
	int sum = 0;;
	int i;
	for (i = start; i < end; i++) {
		sum += arr[i];
	}

	printf("Calculated partial sum: %d\n", sum);

	if (id == 0) {
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(sum)) == -1)
			return 1;
		close(fd[1]);
	} else {
		int sumFromChild;
		close(fd[1]);
		if (read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1)
			return 1;
		close(fd[0]);

		int totalSum = sum + sumFromChild;
		printf("Totalsum is: %d\n", totalSum);
		wait(NULL);
	}
	return (0);
}