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
		if (tbl[i][ft_strlen(tbl[i])-1] == ' ')
			tbl[i][ft_strlen(tbl[i])-1] = '\0';
		tbl[i] = ft_strflip(tbl[i]);
 		if (tbl[i][ft_strlen(tbl[i])-1] == ' ')
			tbl[i][ft_strlen(tbl[i])-1] = '\0';
		tbl[i] = ft_strflip(tbl[i]);
		i++;
	}
	i = 0;
	i2 = 0;
	tbl2 = (char**)malloc(sizeof(char*) * (ft_tbllenskip(tbl) + 1));
	int len2 = ft_tbllen(tbl);
	while(i < len2 )
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

static int  *charrtointti1(char **tbl)
{
	int *tbli;
	int i;

	i = 0;
	tbli = (int*)malloc(sizeof(int *) * (ft_tbllen(tbl)+1));
	while (tbl[i] != NULL)
	{
		tbli[i] = ft_atoi(tbl[i]);	
		i++;
	}

	tbli[i] = INTBLTLIMIT;
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
		//printcharchar(ft_strsplit(tbl[i], ' '));
		i++;
	}
	toreturn[i] = NULL;

	return (toreturn);
}


static int getmaxsizeint(int **tbl)
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

static void intcopy(int *source, int *dest)
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

int **reallocint(int **tbl)
{
	int i;
	int max;
	int *itemp;

	i = 0;
	max = getmaxsizeint(tbl);
	while (tbl[i])
	{
		itemp = (int *)malloc(sizeof(int) * (max+1));
		itemp[max] = INTBLTLIMIT;
		intcopy(tbl[i], itemp);
		tbl[i] = itemp;
		i++;
	}
	return (tbl);
}

static t_point	*ft_ptsnew(int x, int y,int z)
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

t_point		*chrrtocor(int **itbl)
{
	t_point *points;
	t_point *start;
	int i;
	int i2;
	i = 0;
	points = ft_ptsnew(0,0,0);
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
