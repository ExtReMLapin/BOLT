/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:18:44 by pfichepo          #+#    #+#             */
/*   Updated: 2016/01/14 13:18:47 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "minilibx_macos/mlx.h"

unsigned long		creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

inline int			fastmlx_pixel_put(t_env *env, int x, int y, int color)
{
	int h;
	int w;

	h = env->h;
	w = env->w;
	if ((x > w) || (x < 0))
		return (0);
	if ((y > h) || (y < 0))
		return (0);
	return (mlx_pixel_put(env->mlx, env->win, x, y, color));
}

void				ft_singlepointtrans(t_env *e, t_point *p)
{
	p->x_2d = (p->x * e->factor * 3) - (p->y * e->factor * 3) -
	(p->z / (16 * e->factor)) + (e->h / 2);
	p->y_2d = (p->x * e->factor * 2) + (p->y * e->factor * 2) -
	(p->z * (4 * e->factor)) - ((e->h * e->factor) -
	(100 * e->factor));
	p->x_2d += e->offsetx;
	p->y_2d += e->offsety;
}

void				ft_transform2d(t_env *e)
{
	t_point *p;

	p = e->grid;
	while (p)
	{
		ft_singlepointtrans(e, p);
		p = p->next;
	}
}

int					tblmax(int **tbl, int choice)
{
	int i;

	i = 0;
	if (choice == 1)
	{
		while (tbl[i])
			i++;
		return (i);
	}
	if (tbl[0])
	{
		while (tbl[0][i] != INTBLTLIMIT)
			i = i + 1;
		return (i);
	}
	return (1);
}
