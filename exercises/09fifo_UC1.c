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
	srand(time(NULL));
	int i;
	for (i = 0; i < 5; i++) {
		arr[i] = rand() % 100;
		printf("Generated %d\n", arr[i]);
	}

	int fd = open("sum", O_WRONLY);
	if (fd == -1) {
		return 1;
	}
	if (write(fd, arr, sizeof(arr)) == -1)
		return 2;
	close(fd);
	fd = open("sum", O_RDONLY);
	if (fd == -1)
		return 1;
	int sum;
	if (read(fd, &sum, sizeof(sum)) == -1)
		return 1;
	close(fd);
	printf("sum received: %d", sum);
	return (0);
}	