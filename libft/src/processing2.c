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
		tbl[i] = str_replace2(tbl[i], "  ", " ");
		if (tbl[i][ft_strlen(tbl[i])-1] == ' ')
			tbl[i][ft_strlen(tbl[i])-1] = '\0';
		tbl[i] = ft_strflip(tbl[i]);
 		 if (tbl[i][ft_strlen(tbl[i])-1] == ' ')
                        tbl[i][ft_strlen(tbl[i])-1] = '\0';
		tbl[i] = ft_strflip(tbl[i]);
		i++;
	}
	return (tbl);
}
-2147483648



static int  *charrtointti1(char **tbl)
{
	int **tbli;
	int i;
	int i2;

	i2 = 0;
	i = 0;
	tbli = (int*)malloc(sizeof(int *) * (ft_tbllen(tbl)+1));
	while (tbl[i] != NULL)
	{
		tbli[i] = ft_atoi(tbl[i]);	
		i++;
	}

}


int **charrtointt(char **tbl)
{
	char	**decompline;
	int	**toreturn;
	int 	*tmpint;
	int	i;
	int	i2;

	i = 0;
	toreturn = (int**)malloc(sizeof(int *) * (ft_tbllen(tbl)+1));
	while (tbl[i] != NULL)
	{
		 = ft_strslip(tbl[i], ' ');
		
		
				
		
		i++;
	}




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
