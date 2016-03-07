/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:28:53 by pfichepo          #+#    #+#             */
/*   Updated: 2016/01/08 16:48:05 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

static int	*charrtointti1(char **tbl)
{
	int *tbli;
	int i;

	i = 0;
	tbli = (int*)malloc(sizeof(int *) * (ft_tbllen(tbl) + 1));
	if (tbli == NULL)
		error("MALLOC FAIL ON charrtointti1");
	while (tbl[i] != NULL)
	{
		tbli[i] = ft_atoi(tbl[i]);
		i++;
	}
	tbli[i] = INTBLTLIMIT;
	return (tbli);
}

int			**charrtointt(char **tbl)
{
	int	**toreturn;
	int	i;

	i = 0;
	toreturn = (int**)malloc(sizeof(int *) * (ft_tbllen(tbl) + 1));
	if (toreturn == NULL)
		error("MALLOC FAIL ON charrtointt");
	while (tbl[i] != NULL)
	{
		toreturn[i] = charrtointti1(ft_strsplit(tbl[i], ' '));
		i++;
	}
	toreturn[i] = NULL;
	return (toreturn);
}

static int	getmaxsizeint(int **tbl)
{
	int max;
	int i;

	i = 0;
	max = 0;
	while (tbl[i])
	{
		if (nbrintlen(tbl[i]) > max)
			max = nbrintlen(tbl[i]);
		i++;
	}
	return (max);
}

static void	intcopy(int *source, int *dest)
{
	int i;

	i = 0;
	while (source[i] != INTBLTLIMIT)
	{
		dest[i] = source[i];
		i++;
	}
	while (dest[i] != INTBLTLIMIT)
	{
		dest[i] = 0;
		i++;
	}
}

int			**reallocint(int **tbl)
{
	int i;
	int max;
	int *itemp;

	i = 0;
	max = getmaxsizeint(tbl);
	while (tbl[i])
	{
		itemp = (int*)malloc(sizeof(int) * (max + 1));
		if (itemp == NULL)
			error("MALLOC FAIL ON reallocint");
		itemp[max] = INTBLTLIMIT;
		intcopy(tbl[i], itemp);
		tbl[i] = itemp;
		i++;
	}
	return (tbl);
}
