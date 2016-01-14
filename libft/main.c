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

	t_point *pts;
	char **tbl = file_totbl(argv[1]);
	tbl = cleartbl(tbl);;

	int **d = charrtointt(tbl);
	reallocint(d);
	printintint(d);
	pts = chrrtocor(d);


	//printcharchar(test22,  3  test+1);
	return (-1);
}