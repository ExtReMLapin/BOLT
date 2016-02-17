/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:26:51 by pfichepo          #+#    #+#             */
/*   Updated: 2016/02/17 14:26:53 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static inline int	aabs(int x)
{
	return ((x < 0) ? -x : x);
}



static void				fdf_switch_points(t_point *o, t_point *d)
{
	int				t;

	t = d->x;
	d->x = o->x;
	o->x = t;
	t = d->y;
	d->y = o->y;
	o->y = t;
}

static void			fdf_putline_case1(t_point *o, t_point *d, t_env *e)
{
	int				b;
	int				x;
	int				y;

	b = 2 * (aabs(d->x - o->x)) - (d->y - o->y);
	x = o->x;
	y = o->y + 1;
	while (y <= d->y)
	{
		y++;
		if (b >= 0)
		{
			x += (d->x > o->x ? 1 : -1);
			b += 2 * ((aabs(d->x - o->x)) - (d->y - o->y));
		}
		else
			b += (2 * aabs(d->x - o->x));
		fastmlx_pixel_put(e, x, y, 0xFFFFFF);
	}
}

static void			fdf_putline_case2(t_point *o, t_point *d, t_env *e)
{
	int				b;
	int				x;
	int				y;

	b = 2 * (aabs(d->y - o->y)) - (d->x - o->x);
	x = o->x + 1;
	y = o->y;
	while (x <= d->x)
	{
		x++;
		if (b >= 0)
		{
			y += (d->y > o->y ? 1 : -1);
			b += (2 * ((aabs(d->y - o->y)) - (d->x - o->x)));
		}
		else
			b += (2 * (aabs(d->y - o->y)));
		fastmlx_pixel_put(e, x, y, 0xFFFFFF);
	}
}

void				fdf_putline(t_point *o, t_point *d, t_env *e)
{
	if (aabs(d->x - o->x) < aabs(d->y - o->y))
	{
		if (o->y > d->y)
			fdf_switch_points(o, d);
		fdf_putline_case1(o, d, e);
	}
	else
	{
		if (o->x > d->x)
			fdf_switch_points(o, d);
		fdf_putline_case2(o, d, e);
	}
}