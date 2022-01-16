#include <unistd.h>
#include <sys/types.h>

#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

// How to separate a problem resolution in 2 processes to make them work in paralel 
// (1 pipe -> paralel treatment with unidirectional exchange at the end)
int main(int argc, char* argv[]) 
{
    int arr[] = { 1, 2, 3, 4, 1};
    int arrSize = sizeof(arr) / sizeof(int);		// => taille de arr en bytes / taille de int en bytes	=>	(5 * 4) / 4 = 5		=> arrayLength
    int start, end;
    int fd[2];

    if (pipe(fd) == -1) 
        return 1;
    int id = fork();
    if (id == -1)
        return 2;
    
    if (id == 0) 
	{
        start = 0;
        end = arrSize / 2;
    } 
	else 
	{
        start = arrSize / 2;
        end = arrSize;
    }
    
    int sum = 0;
    int i;
    for (i = start; i < end; i++) 
        sum += arr[i];
    
    printf("Calculated partial sum: %d\n", sum);
    
    if (id == 0) 
	{
        close(fd[0]);
        if (write(fd[1], &sum, sizeof(int)) == -1)
            return 3;
        close(fd[1]);
    } 
	else 
	{
        int sumFromChild;
        close(fd[1]);
        if (read(fd[0], &sumFromChild, sizeof(int)) == -1)
            return 4;
        close(fd[0]);
        
        int totalSum = sum + sumFromChild;
        printf("Total sum is %d\n", totalSum);

		wait(NULL);		// we have to wait termination of child process to be sure to have his complete partial sum to read from
    }
    
    return 0;
}