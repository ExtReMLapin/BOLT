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

	t = d->x_2d;
	d->x_2d = o->x_2d;
	o->x_2d = t;
	t = d->y_2d;
	d->y_2d = o->y_2d;
	o->y_2d = t;
}

static void			fdf_putline_case1(t_point *o, t_point *d, t_env *e)
{
	int				b;
	int				x;
	int				y;

	b = 2 * (aabs(d->x_2d - o->x_2d)) - (d->y_2d - o->y_2d);
	x = o->x_2d;
	y = o->y_2d + 1;
	while (y <= d->y_2d)
	{
		y++;
		if (b >= 0)
		{
			x += (d->x_2d > o->x_2d ? 1 : -1);
			b += 2 * ((aabs(d->x_2d - o->x_2d)) - (d->y_2d - o->y_2d));
		}
		else
			b += (2 * aabs(d->x_2d - o->x_2d));
		fastmlx_pixel_put(e, x, y, 0xFFFFFF);
	}
}

static void			fdf_putline_case2(t_point *o, t_point *d, t_env *e)
{
	int				b;
	int				x;
	int				y;

	b = 2 * (aabs(d->y_2d - o->y_2d)) - (d->x_2d - o->x_2d);
	x = o->x_2d + 1;
	y = o->y_2d;
	while (x <= d->x_2d)
	{
		x++;
		if (b >= 0)
		{
			y += (d->y_2d > o->y_2d ? 1 : -1);
			b += (2 * ((aabs(d->y_2d - o->y_2d)) - (d->x_2d - o->x_2d)));
		}
		else
			b += (2 * (aabs(d->y_2d - o->y_2d)));
		fastmlx_pixel_put(e, x, y, 0xFFFFFF);
	}
}

void				fdf_putline(t_point *o, t_point *d, t_env *e)
{
	if (aabs(d->x_2d - o->x_2d) < aabs(d->y_2d - o->y_2d))
	{
		if (o->y_2d > d->y_2d)
			fdf_switch_points(o, d);
		fdf_putline_case1(o, d, e);
	}
	else
	{
		if (o->x_2d > d->x_2d)
			fdf_switch_points(o, d);
		fdf_putline_case2(o, d, e);
	}
}