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

unsigned long createRGB(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}


int	fastmlx_pixel_put(t_env *env, int x, int y, int color)
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

void drawbox(int x , int y, int w, int h, int c, t_env *env)
{
	int i;
	int i2;
	int b;
	int b2;

	i = 0;
	while (w > i)
	{
		i2 = x+i;
		b = 0;
		while (h > b)
		{
			b2 = y+b;
			fastmlx_pixel_put(env, i2, b2, c);
			b++;
		}	
		i++;
	}
}


void		ft_transform2d(t_point *p, t_env *e)
{

	p->x_2d = (p->x * e->factor * 3) - (p->y * e->factor * 3) -
			(p->z / (16 * e->factor)) + (e->h / 2);
	p->y_2d = (p->x * e->factor * 2) + (p->y * e->factor * 2) -
		(p->z * (16 * e->factor)) - ((e->h * e->factor) -
				(1000 * e->factor));
}