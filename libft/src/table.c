/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 15:14:14 by pfichepo          #+#    #+#             */
/*   Updated: 2015/12/01 15:49:20 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		putnbrint(int *tbl)
{
	int i;

	i = 0;
	while (tbl[i] != INTBLTLIMIT)
	{
		ft_putnbr(tbl[i]);
		ft_putchar(' ');
		i++;
	}
}

void			printintint(int **tbl)
{
	int i;

	i = 0;
	ft_putstr("\n-Integer Table Print Start\n");
	while (tbl[i] != NULL)
	{
		ft_putstr("\033[1;31m[");
		ft_putnbr(i);
		ft_putstr("]\033[0m");
		ft_putstr("| Integer table size : \033[1;34m");
		ft_putnbr(nbrintlen(tbl[i]));
		ft_putstr(" \033[0m| Content : ");
		putnbrint(tbl[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("-Integer Table Print End\n\n");
}

void			printcoortbl(t_point *t)
{
	int i;

	i = 0;
	ft_putstr("\n-Table Print Start\n");
	while (t != NULL)
	{
		ft_putstr("[");
		ft_putnbr(i++);
		ft_putstr("]");
		ft_putstr(" | X :");
		ft_putnbr(t->x);
		ft_putstr(" | Y :");
		ft_putnbr(t->y);
		ft_putstr(" | Z :");
		ft_putnbr(t->z);
		ft_putchar('\n');
		if (!(t->next))
			break ;
		t = t->next;
	}
	ft_putstr("-Table Print End\n\n");
}

static char		**ezclear(char **tbl)
{
	int i;

	i = 0;
	while (tbl[i] != NULL)
	{
		tbl[i] = rem_nonnum(tbl[i]);
		tbl[i] = str_replace2(tbl[i], "  ", " ");
		if (tbl[i][ft_strlen(tbl[i]) - 1] == ' ')
			tbl[i][ft_strlen(tbl[i]) - 1] = '\0';
		tbl[i] = ft_strflip(tbl[i]);
		if (tbl[i][ft_strlen(tbl[i]) - 1] == ' ')
			tbl[i][ft_strlen(tbl[i]) - 1] = '\0';
		tbl[i] = ft_strflip(tbl[i]);
		i++;
	}
	return (tbl);
}

char			**cleartbl(char **tbl)
{
	int		i;
	int		i2;
	char	**tbl2;

	ezclear(tbl);
	i = 0;
	i2 = 0;
	tbl2 = (char**)malloc(sizeof(char*) * (ft_tbllenskip(tbl) + 1));
	while (i < ft_tbllen(tbl))
	{
		if (ft_strlen(tbl[i]) > 0)
		{
			tbl2[i2] = ft_strdup(tbl[i]);
			i2++;
		}
		i++;
	}
	tbl2[i2] = NULL;
	return (tbl2);
}
