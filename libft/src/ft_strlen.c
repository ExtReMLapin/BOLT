/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:18:21 by pfichepo          #+#    #+#             */
/*   Updated: 2015/09/16 11:48:16 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


int ft_tbllen(char **tbl)
{
	int i;
	if (!tbl)
		error("TBL LEN SEGFAULT");

	i = 0;
	while (tbl[i] != NULL)
		i++;
	return (i);
}

int nbrintlen(int *tbl)
{
	int i;

	i = 0;
	while (tbl[i] != INTBLTLIMIT)
		i++;
	return (i);
}

int ft_tbllenskip(char **tbl)
{
	int i;
	int i2;
	
	if (!tbl)
		 error("TBL LEN SKIP  SEGFAULT");
	i = 0;
	i2 = 0;
	while (tbl[i] != NULL)
	{
		if (ft_strlen(tbl[i]) > 0)
			i2++;
		i++;
	}
	return (i2);
}

