#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

// fd[0] - read
// fd[1] - write

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,10};
	int arr_size = sizeof(arr) / sizeof(int);
	int start;
	int end;
	int p1[2];
	int p2[2];
	int id1;
	int id2;

	if (pipe(p1) == -1) {return 1;}
	if (pipe(p2) == -1) {return 1;}

	id1 = fork();
	wait(NULL);
	if (id1 == -1)
		return 1;
	if (id1 == 0)
	{
		printf("I'm here\n");
		id2 = fork();
		if (id2 == -1)
			return 1;
	} else {
		return (1);
	}

	if (id1 == 0)
	{
		start = 0;
		end = arr_size / 2;
	}
	else if (id2 == 0)
	{
		start = arr_size / 2;
		end = arr_size;
	}
	// int sum = 0;
	int partial = 0;
	if (id1 == 0)
		partial = 5;
	if (id2 == 0)
		partial = 10;
	// if (id1 == 0 || id2 == 0)
	// {
	// 	for (int i = start; i < end; i++)
	// 		sum += arr[i];
	// }
	if (id1 == 0)
		printf("child 0, partial: %d\n", partial);
	if (id2 == 0)
		printf("child 1, partial: %d\n", partial);
	if (id1 == 0)
	{
		close(p1[0]);
		if (write(p1[1], &partial, sizeof(partial)) == -1)
			return (1);
		close(p1[1]);
	} else if (id2 == 0) {
		close(p2[0]);
		if (write(p2[1], &partial, sizeof(partial)) == -1)
			return (1);
		close(p2[1]);
	} else {
		close(p1[1]);
		close(p2[1]);
		int part1;
		int part2;
		if (read(p1[0], &part1, sizeof(part1)) == -1)
			return (1);
		if (read(p2[0], &part2, sizeof(part2)) == -1)
			return (1);
		close(p1[0]);
		close(p2[0]);
		int tot = part1 + part2;
		printf("total: %d\n", tot);
		wait(NULL);
	}
	
	return (0);
}