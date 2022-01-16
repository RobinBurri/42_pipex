#include <unistd.h>
#include <sys/types.h>
#include <time.h>

#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

// Communication between two processes with two pipes (2 pipes -> bidirectional chained treatement)

// Generate a num in Parent process and pass it to Child process
// In Child p., muliticate the num by 4 and send it back to Parent p.
int main(int argc, char* argv[]) {
	// Creating two pipes
	int p1[2];	// C => P
    int p2[2];	// P => C

    if (pipe(p1) == -1)
		printf("\n0\n");
    if (pipe(p2) == -1)
		printf("\n1\n");
    int pid = fork();
    if (pid == -1)
		printf("\n2\n");

    if (pid == 0) 						// Child process
	{
        close(p1[0]);
        close(p2[1]);
        
        int x;
        if (read(p2[0], &x, sizeof(int)) == -1)
            printf("\n3\n");
        printf("Received %d\n", x);
        
        x *= 4;
        
        if (write(p1[1], &x, sizeof(int)) == -1)
            printf("\n4\n");
        printf("Wrote %d\n", x);

        close(p1[1]);
        close(p2[0]);
    } 
	else 								// Parent process
	{
        close(p1[1]);
        close(p2[0]);
        
        srand(time(NULL));
        int y = rand() % 10;
        
        if (write(p2[1], &y, sizeof(y)) == -1)
            printf("\n5\n");
        printf("Wrote %d\n", y);
        if (read(p1[0], &y, sizeof(y)) == -1)
            printf("\n6\n");
        printf("Result is %d\n", y);

        close(p1[0]);
        close(p2[1]);
		wait(NULL);
    }
    
    return 0;
}