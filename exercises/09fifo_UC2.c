#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

// /UNIX PROCESSES IN C { CODEVAULT },video - 09 FIFO communication between processes

int main(int argc, char *argv[])
{
	int arr[5];

	int fd = open("sum", O_RDONLY);
	if (fd == -1)
		return 1;
	int i;
	if (read(fd,&arr[i], sizeof(arr)) == -1)
		return 2;
	close(fd);
	int sum;
	for (i = 0; i < 5; i++)
	{
		sum += arr[i];
	}
	printf("UC2: %d\n", sum);
	// Exercise send the sum back to UC1
	// STEP 1, in UC2: open the fifo again and write into it and close it
	fd = open("sum", O_WRONLY);
	if (fd == -1)
		return 1;
	if (write(fd, &sum, sizeof(sum)) == -1)
		return 2;
	printf("sum send\n");
	close(fd);
	// STEP 2, in UC1: open the fifo, read from it and close it.
	return (0);
}	