/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 14:17:59 by pfichepo          #+#    #+#             */
/*   Updated: 2016/01/14 14:18:00 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "include/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{

	ft_putstr("Loading file ... \n");
	char **tbl =file_totbl(argv[1]) ;
	ft_putstr("clearing ... \n");
	tbl = cleartbl(tbl);
	ft_putstr("converting to int ... \n");
	int **itbl = charrtointt(tbl);
	ft_putstr("resizing lines ... \n");
	reallocint(itbl);
	ft_putstr("converting to list coord ... \n");
	t_point *pts = chrrtocor(itbl);
	ft_putstr("saving ... \n");
	ft_putstr("Done !\n");

	//printcharchar(test22,  3  test+1);
	return (-1);
}