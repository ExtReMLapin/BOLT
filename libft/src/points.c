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

static t_point	*ft_ptsnew(int x, int y, int z)
{
	t_point	*lst;

	lst = (t_point*)malloc(sizeof(t_point));
	if (lst == NULL)
		return (NULL);
	lst->x = x;
	lst->y = y;
	lst->z = z;
	lst->next = NULL;
	return (lst);
}

static void		addpointend(t_point *tbl, int x, int y, int z)
{
	t_point	*tmp;

	tmp = tbl;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_ptsnew(x, y, z);
}

t_point			*chrrtocor(int **itbl)
{
	t_point	*points;
	t_point	*start;
	int		i;
	int		i2;

	i = 0;
	points = ft_ptsnew(0, 0, 0);
	start = points;
	while (itbl[i] != NULL)
	{
		i2 = 0;
		while (itbl[i][i2] != INTBLTLIMIT)
		{
			addpointend(points, i2, i, itbl[i][i2]);
			i2++;
		}
		i++;
	}
	return (start);
}
