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

void				drawbox(t_box *box, t_env *env)
{
	int i;
	int i2;
	int b;
	int b2;

	i = 0;
	while (box->w > i)
	{
		i2 = box->x + i;
		b = 0;
		while (box->h > b)
		{
			b2 = box->y + b;
			fastmlx_pixel_put(env, i2, b2, box->c);
			b++;
		}
		i++;
	}
}
