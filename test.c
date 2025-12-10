#include "includes/pipex.h"

int main(void)
{
	int fd = open("outfile", O_RDWR);
	dup2(fd, 2048);
	return (1);
}