#include "include/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{

	t_point *pts;
	char **tbl = file_totbl(argv[1]);
	tbl = cleartbl(tbl);;
	int **d = charrtointt(tbl);
	reallocint(d);
	pts = chrrtocor(d);


	//printcharchar(test22,  3  test+1);
	return (-1);
}
