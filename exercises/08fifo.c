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
		// mkfifo will return a error if myfifo already exist but 
		//it's fine for us  so we filter out for that
		if (errno != EEXIST)
		{
			printf("Couldn't create fifo file\n");
			return (1);
		}
	}
	printf("opening...\n");
	fd = open("myfifo1", O_WRONLY);
	// Opening the read or write end of a FIFO blocks 
	//until the other end is also opened (by another process or thread).  
	//See fifo(7) for further details.
	printf("opened...\n");
	if (fd == -1)
		return (2);
	int x = 97;
	if (write(fd, &x, sizeof(x)) == -1)
		return (3);
	printf("closing...\n");
	close(fd);
	printf("closed...\n");
	return 0;
}

// you can read myfifo1 from a terminal with cat
// myfifol1 and it will end this program