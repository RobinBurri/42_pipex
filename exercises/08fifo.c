#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

// /UNIX PROCESSES IN C { CODEVAULT },video - 08 FIFO

int main()
{
	int fd;
	if (mkfifo("myfifo1", 0777) == -1)
	{
		if (errno != EEXIST)
		{
			printf("Couldn't create fifo file\n");
			return (1);
		}
	}
	fd = open("myfifo1", O_WRONLY);
	if (fd == -1)
		return (2);
	int x = 97;
	if (write(fd, &x, sizeof(x)) == -1)
		return (3);
	close(fd);
	return 0;
}