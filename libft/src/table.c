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

int		table_hasvalue(t_list *t, void *value)
{
	int i;

	i = 0;
	if (!t)
		return (-42);
	while (t->next)
	{
		if (ft_strcmp((char *)(t->content), (char *)(value)) == 0)
			return (i);
		t = t->next;
		i++;
	}
	return (-1);
}

int		table_getsize(t_list *t)
{
	int i;

	i = 0;
	if (!t)
	{
		ft_putstr("Table not valid\n");
		return (0);
	}
	while (t != NULL)
	{
		i++;
		if (!(t->next))
			break ;
		t = t->next;
	}
	return (i);
}

void	table_insert(t_list *t, int pos, t_list *new)
{
	int		i;
	int		size;
	t_list	*tmp;

	i = 0;
	size = table_getsize(t);
	if (!t || !new || pos > size || pos < 1)
	{
		errornohalt("Table not valid or pos not valid");
		return ;
	}
	while (i != pos - 1)
	{
		t = t->next;
		i++;
	}
	tmp = t->next;
	t->next = new;
	ft_lstaddend(&t, tmp);
	return ;
}








void	printtable(t_list *t)
{
	int i;

	i = 0;
	ft_putstr("\n-Table Print Start\n");
	while (t != NULL)
	{
		ft_putstr("\033[1;31m[");
		ft_putnbr(i++);
		ft_putstr("]\033[0m");
		ft_putstr("| Content size : \033[1;34m");
		ft_putnbr(t->content_size);
		ft_putstr(" \033[0m| Content : ");
		ft_putstr_force((char *)(t->content), t->content_size);
		ft_putchar('\n');
		if (!(t->next))
			break ;
		t = t->next;
	}
	ft_putstr("-Table Print End\n\n");
}


void	printcoortbl(t_point *t)
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

void	printcharchar(char **tbl)
{
	int i;

	i = 0;
	ft_putstr("\n-String Table Print Start\n");
	while (tbl[i] != NULL)
	{
		ft_putstr("\033[1;31m[");
		ft_putnbr(i);
		ft_putstr("]\033[0m");
		ft_putstr("| String size : \033[1;34m");
		ft_putnbr(ft_strlen(tbl[i]));
		ft_putstr(" \033[0m| Content : ");
		ft_putstr(tbl[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("-String Table Print End\n\n");
}


static void putnbrint(int *tbl)
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

void	printintint(int **tbl)
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
