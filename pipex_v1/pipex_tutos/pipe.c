#include <unistd.h>
#include <sys/types.h>

#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

// How to send memory between processes after the fork
// (1 pipe -> unidirectional chained treatment)
int main(int argc, char* argv[]) {

    int pipefd[2];
	// The array pipefd is used to return two file descriptors referring to the ends of the pipe.
	// pipefd[0] refers to the read end of the pipe. 
	// pipefd[1] refers to the write end of the pipe.

    if (pipe(pipefd) == -1)		// pipe() save the new file descriptors opened in the array pipefd
	{
        printf("An error ocurred with opening the pipe\n");
        return 1;
    }
	// On success, zero is returned.  On error, -1 is returned, errno is set to indicate the error
    
    int id = fork();
    if (id == -1) 
	{
        printf("An error ocurred with fork\n");
        return 2;
    }
    
    if (id == 0) 				// Child process
	{
        close(pipefd[0]);
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        if (write(pipefd[1], &x, sizeof(int)) == -1) 
		{
            printf("An error ocurred with writing to the pipe\n");
            return 3;
        }
        close(pipefd[1]);
    } 
	else 						// Parent process
	{
        close(pipefd[1]);
        int y;
        if (read(pipefd[0], &y, sizeof(int)) == -1) 
		{
            printf("An error ocurred with reading from the pipe\n");
            return 4;
        }
        printf("Got from child process %d\n", y);
        close(pipefd[0]);
    }
    
    return 0;
}