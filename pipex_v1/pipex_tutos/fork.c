#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(void)
{
	pid_t	id;
	id = fork();			// fork main process in main (id > 0) + child (id = 0) processes
	if(id != 0)
		fork();				// fork main pocess in main (id > 0) + child (id = 0) processes
							// here we have 3 processes (2 + 1)
	printf("test\n");

	// fork();				// fork main process in main (id > 0) + child (id = 0) processes
	// fork();				// fork main pocesses in main (id > 0) + child (id = 0) processes
	// 						// here we have 4 processes (2 ^ 2)
	// printf("test\n");
	
	return (0);
}

// fork copy all the main process in a child process that start with the same memory
// but that memory is not located at the same adresses. It's a “duplicated"
// the changes in child process won't affect memory in main process