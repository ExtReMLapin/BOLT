/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ddraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:48:35 by pfichepo          #+#    #+#             */
/*   Updated: 2016/03/14 15:48:36 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "minilibx_macos/mlx.h"

long math_remap(long x, long in_min, long in_max, long out_min, long out_max)
{
	int a;
	int b;
	int c;
	int d;

	a = (x - in_min);
	b = (out_max - out_min);
	c = (in_max - in_min);
	d = out_min;
	if (c == 0)
		return (0);
	return (a * b / c + d);
}

void				mapsize2(t_env *env)
{
	t_point		*map;
	int			zmax;
	int			zmin;

	map = env->grid;
	zmax = map->z;
	zmin = map->z;
	while (map)
	{
		if (map->z < zmin)
			zmin = map->z;
		if (map->z > zmax)
			zmax = map->z;
		map = map->next;
	}
	env->maxz = zmax;
	env->minz = zmin;
}

void				calczoom(t_env *env)
{
	int result;

	printf("%i %i\n", env->mapx, env->mapy);
	if ((env->mapx > env->w) || (env->mapy > env->h))
	{
		env->zoom = 1;
		return ;
	}
	if  (env->mapx > env->mapy)
	{
		if (env->mapy > env->h)
			result = ((env->h - OFFSETBOX) / env->mapy);
		else
			result = ((env->w) / env->mapx);
	}
	else
		result = ((env->h - OFFSETBOX) / env->mapy);
	env->zoom = result;
}

void			drawmap2d(t_env *env)
{
	t_point	*dickbutt;
	int		x;
	int		y;
	int		c;
	int		c1;
	dickbutt = env->grid;
	while (dickbutt != NULL)
	{
		x = dickbutt->x * env->zoom;
		y = dickbutt->y * env->zoom + OFFSETBOX;
		c1 = math_remap(dickbutt->z, env->minz, env->maxz, 0, 255);
		c = creatergb(c1, c1, c1);
		drawbox(x , y, env->zoom, env->zoom, c, env);
		dickbutt = dickbutt->next;
	}
}


