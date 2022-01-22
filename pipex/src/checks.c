#include "../pipex.h"

// create a pipe for 
//input.txt >> grep "tes" | wc -l >> output.txt

int open_check_files(char *input, char *output, int *fdin, int *fdout, int argc)
{
	// if (argc != 5)
	// {
	// 	ft_putstr_fd("Usage: ./pipex [file1] [cmd1] [cmd2] [file2]", 2);
	// 	exit(1);
	// }
	*fdin = open(input, O_RDONLY);
	*fdout = open(output, O_WRONLY | O_CREAT |S_IRUSR | S_IWUSR);
	if (*fdin == -1|| *fdout == -1)
	{
		printf("OPEN ERROR");
		exit(2);
	}
	return (0);
}

void 	close_check_files(int fdin, int fdout)
{
	int c1;
	int c2;
	c1 = close(fdin);
	c2 = close(fdout);
	if (c2 != 0 || c1 != 0)
	{
		printf("CLOSE ERROR");
		exit(3);
	}
}