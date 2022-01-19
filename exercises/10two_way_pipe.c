#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

// UNIX PROCESSES IN C { CODEVAULT }, video 10- Two way communication between proccesses
// TWO WAY COMMUNICATION BETWEEN PROCESSES WITH PIPES
//  pipe() 8 * 4 pipe() back / print; (1) -> (2) -> (1)
int main()
{
	int p1[2]; // C => P
	int p2[2]; // P => C

	if (pipe(p1) == - 1) { return 1; }
	if (pipe(p2) == - 1) { return 1; }
	int pid = fork();
	if (pid == -1) {return 2;}
	if (pid == 0) {
		// Child process
		close(p1[0]); //close the read end
		close(p2[1]);// close the write end
		int x;
		if (read(p2[0], &x, sizeof(x)) == -1) {return 3;}
		printf("child received %d\n", x);
		x *= 4;
		if (write(p1[1], &x, sizeof(x)) == -1) {return 4;}
		printf("child wrote %d\n", x);
		close(p2[0]);
		close(p1[1]);
	} else {
		// Parent process
		close(p1[1]); // close the write end
		close(p2[0]); // close the read end
		int y = 8;
		if (write(p2[1], &y, sizeof(y)) == -1) {return 5;}
		printf("parent wrote %d\n", y);
		if (read(p1[0], &y, sizeof(y)) == -1) {return 6;}
		printf("Parent Result is %d\n", y);
		close(p1[0]);
		close(p2[1]);
		wait(NULL);
	}
	return (0);
}