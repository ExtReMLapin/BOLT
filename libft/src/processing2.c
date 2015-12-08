/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:28:53 by pfichepo          #+#    #+#             */
/*   Updated: 2015/12/03 16:07:58 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**cleartbl(char **tbl)
{
	int i;

	i = 0;
	while (tbl[i] != NULL)
	{
		tbl[i] = rem_nonnum(tbl[i]);

		tbl[i] = str_replace2(tbl[i], " \0", "");
		tbl[i] = ft_strflip(tbl[i]);
		tbl[i] = str_replace2(tbl[i], " \0", "");
		tbl[i] = ft_strflip(tbl[i]);
		tbl[i] = str_replace2(tbl[i], "  ", " ");
		i++;
	}
	return (tbl);
}

static t_point	*ft_ptsnew(int x, int y)
{
	t_point	*lst;

	lst = (t_point*)malloc(sizeof(t_point));
	if (lst == NULL)
		return (NULL);
	lst->x = x;
	lst->y = y;
	lst->next = NULL;
	return (lst);
}

static void		addpointend(t_point **tbl, int x, int y)
{
	t_point	*tmp;

	tmp = *tbl;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_ptsnew(x, y);
}

t_point		*chrrtocor(char **tbl)
{
	t_point *points;
	t_point *start;
	int i;
	int i2;

	i = 0;

	points = (t_point*)malloc(sizeof(t_point));
	start = points;
	while (tbl[i] != NULL)
	{
		i2 = 0;
		while (tbl[i][i2])
		{
			addpointend(&points, i2, i);
			i2++;
		}	

	i++;
	}
	return (start);
}
