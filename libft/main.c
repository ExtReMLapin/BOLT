#include "include/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


static int stringinstring(char *str, char *in)
{
	int i;
	int i2;
	int len;
	int len2;

	i = 0;
	len = ft_strlen(str);
	len2 = ft_strlen(in);
	if (len2 > len)
		return (-1);
	while (str[i])
	{
		i2 = 0;
		if (i > (len-len2))
			break;
		while(in[i2] && (str[i] == in[i2]))
		{
			i++;
			i2++;
		}
		if (i2 == len2)
			return (i-len2);
		if (i2 == 0)
			i++;
	}
	return (-1);
}


int main(int argc, char **argv)
{
	/*t_list *tbl;
	t_list *cache;
	t_list *dick;
	int i = 0;
	tbl = (t_list*)malloc(sizeof(t_list));
	char *lol = "lol";
	tbl->content = (void *)lol;
	tbl->content_size = 4;
	tbl->next = NULL;

	dick = (t_list*)malloc(sizeof(t_list));
	dick->content = (void *)lol;
	dick->content_size = 4;
	dick->next = NULL;

	while(i < argc)
	{
		cache = (t_list*)malloc(sizeof(t_list));
		cache->content = ft_strdup(argv[i]);
		cache->content_size = ft_strlen(argv[i]);
		cache->next = NULL;
		ft_lstaddend(&tbl, cache);
		i++;
	}
	table_insert(tbl, 2,dick );
	printtable(tbl);
	ft_putnbr(table_getsize(tbl));*/

	char **tbl = file_totbl(argv[1]);
	tbl = cleartbl(tbl);
	int ** = 
	
	printcharchar(tbl);




	/*int		fd;
	char	*line;

	if (argc > 1)
	{
 		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			printf("Line ; %s\n", line);
			free(line);
			line = NULL;
		}

	}
	return (0);*/


	//printcharchar(test2, test+1);
	return (1);
}