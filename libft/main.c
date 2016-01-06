#include "include/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{

	char **tbl = file_totbl(argv[1]);
	tbl = cleartbl(tbl);
	printcharchar(tbl);
	int **d = charrtointt(tbl);

	printintint(d);

	while (1)
	{

	}

	//printcharchar(test22,  3  test+1);
	return (-1);
}
