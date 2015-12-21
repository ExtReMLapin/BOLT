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
	int i2;
	char **tbl2;

	i = 0;
	while (tbl[i] != NULL)
	{
		tbl[i] = rem_nonnum(tbl[i]);
		tbl[i] = str_replace2(tbl[i], "  ", " ");
		/*if (tbl[i][ft_strlen(tbl[i])-1] == ' ')
			tbl[i][ft_strlen(tbl[i])-1] = '\0';
		tbl[i] = ft_strflip(tbl[i]);
 		if (tbl[i][ft_strlen(tbl[i])-1] == ' ')
			tbl[i][ft_strlen(tbl[i])-1] = '\0';
		tbl[i] = ft_strflip(tbl[i]);*/
		i++;
	}
	i = 0;
	i2 = 0;
	tbl2 = (char**)malloc(sizeof(char*) * (ft_tbllenskip(tbl) + 1));
	while(i < ft_tbllen(tbl))
	{
		if (ft_strlen(tbl[i]) > 0)
		{
			ft_putstr(tbl[i]);
			tbl2[i2] = ft_strdup(tbl[i]);
			ft_putstr(tbl[i2]);
			i2++;
		}
		i++;
	}
	tbl2[i] = NULL;
	return (tbl2);
}

static int  *charrtointti1(char **tbl)
{
	int *tbli;
	int i;
	ft_putnbr(ft_tbllen(tbl));
	ft_putstr("kek");
	i = 0;
	tbli = (int*)malloc(sizeof(int *) * (ft_tbllen(tbl)+1));
	while (tbl[i] != NULL)
	{
		tbli[i] = ft_atoi(tbl[i]);	
		i++;
	}

	tbli[i] = -2147466666;
	return (tbli);
}


int **charrtointt(char **tbl)
{
	int	**toreturn;
	int	i;

	i = 0;
	toreturn = (int**)malloc(sizeof(int *) * (ft_tbllen(tbl)+1));
	while (tbl[i] != NULL)
	{
		toreturn[i] = charrtointti1(ft_strsplit(tbl[i], ' '));
		i++;
	}
	toreturn[i] = charrtointti1(ft_strsplit(tbl[i], ' '));
	toreturn[i][0] = 2147466666;
	return (toreturn);
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

t_point		*chrrtocor(int **itbl)
{
	t_point *points;
	t_point *start;
	int i;
	int i2;

	i = 0;

	points = (t_point*)malloc(sizeof(t_point));
	start = points;
	while (itbl[i] != NULL)
	{
		i2 = 0;
		while (itbl[i][i2])
		{
			addpointend(&points, i2, i);
			i2++;
		}	

	i++;
	}
	return (start);
}
