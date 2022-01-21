#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
 
// UNIX PROCESSES IN C { CODEVAULT }, video 23 - Simulating the pipe orerator
// simulating "ping -c 5 google.com | grep round-trip"
/*
	main process will creat two process: (one for ping and one for grep)(same level children) 
	& a pipe to let the output of ping flow in grep
*/
int main() {

	//create the pipe
	int pfd[2];
	if (pipe(pfd) == -1)
		return 1;
	// create processes
	int pid1 = fork();
	if (pid1 < 0) 
		return 2;

	if (pid1 == 0) {
		// child for ping
		close(pfd[0]);
		//reroute output
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}

	int pid2 = fork();
	if (pid2 < 0)
		return 3;
	if (pid2 == 0)
	{
		//child for grep
		close(pfd[1]);
		dup2(pfd[0], STDIN_FILENO);
		close(pfd[0]);
		execlp("grep", "grep", "round-trip", NULL);
	}
	// MUST close the pipe on main otherwise grep won't finish
	close(pfd[0]);
	close(pfd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
