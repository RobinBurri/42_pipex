#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// UNIX PROCESSES IN C { CODEVAULT }, video 18 background, foreground process
// UNIX PROCESSES IN C { CODEVAULT }, video 19 Handling signals your own way with 
// SIGACTION


// ctrl + Z = process stop == SIGSTP
// fg = continue process == SIGCONT

// HANDLE SIGSTP DIFFERENTLY THAN DEFAULT
// void handle_sigstp(int sig) {
// 	printf("\nStop not allowed\n");
// }
// HANDLE SIGCONT DIFFERENTLY THAN DEFAULT
void handle_sigcont(int sig) {
	printf("Input number: ");
	fflush(stdout);
}

int main(void)
{
	// SIGACTION
	// struct sigaction sa;
	// sa.sa_handler = &handle_sigstp;
	// sa.sa_flags = SA_RESTART;
	// sigaction(SIGTSTP, &sa, NULL);

	struct sigaction sa1;
	sa1.sa_handler = &handle_sigcont;
	sa1.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &sa1, NULL);

	int x;
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x , x *5);
	return (0);
}