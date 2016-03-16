/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:50:52 by pfichepo          #+#    #+#             */
/*   Updated: 2016/01/14 13:50:54 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_point			*ft_ptsnew(int x, int y, int z)
{
	t_point	*lst;

	lst = (t_point*)malloc(sizeof(t_point));
	if (lst == NULL)
		error("MALLOC FAIL ON ft_ptsnew");
	lst->x = x;
	lst->y = y;
	lst->z = z;
	lst->next = NULL;
	return (lst);
}

int pointsnb(t_point *pt)
{
	t_point	*pt2;
	int i;

	pt2 = pt;
	i = 0;
	while (pt2)
	{
		i++;
		pt2 = pt2->next;
	}
	return (i);
}

static t_point	*addpointend(t_point *tbl, int x, int y, int z)
{
	t_point	*tmp;

	tmp = tbl;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_ptsnew(x, y, z);
	return (tmp->next);
}


static void		freecharint(int **tbl)
{
	int i;

	i = 0;
	while (tbl[i])
	{
		free(tbl[i]);
		i++;
	}
	free(tbl);
}


t_point			*chrrtocor(int **itbl)
{
	t_point	*points;
	t_point	*start;
	int		i;
	int		i2;
	int		skip;

	i = 0;
	points = ft_ptsnew(0, 0, itbl[0][0]);
	start = points;
	skip = 1;
	while (itbl[i] != NULL)
	{
		if (skip == 1)
		{
			i2 = 0;
			skip = 0;
		}
		else
			i2 = -1;
		while (itbl[i][++i2] != INTBLTLIMIT)
			points = addpointend(points, i2, i, itbl[i][i2]);
		i++;
	}
	freecharint(itbl);
	return (start);
}
