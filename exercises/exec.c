#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	//execl("/sbin/ping", "/sbin/ping", "google.com", NULL);
	// OR
	//char *arr[] = { "ping", "google.com", NULL};
	//execvp("ping", arr);
	//OR
	execlp("ping", "ping", "google.com", NULL);
	return (0);
}
