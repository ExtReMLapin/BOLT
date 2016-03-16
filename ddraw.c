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

static unsigned int	math_remap(long x, long in_min, long in_max)
{
	int a;
	int c;

	a = (x - in_min);
	c = (in_max - in_min);
	if (c == 0)
		return (0);
	return (a * 255 / c);
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

	if ((env->mapx > env->w) || (env->mapy > env->h))
	{
		env->zoom = 1;
		return ;
	}
	if (env->mapx > env->mapy)
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

void				drawmap2d(t_env *env)
{
	t_point	*dickbutt;
	int		c1;
	t_box	*box;

	dickbutt = env->grid;
	while (dickbutt != NULL)
	{
		box = (t_box*)malloc(sizeof(t_box));
		box->x = dickbutt->x * env->zoom;
		box->y = dickbutt->y * env->zoom + OFFSETBOX;
		c1 = math_remap(dickbutt->z, env->minz, env->maxz);
		box->c = creatergb(c1, c1, c1);
		box->w = env->zoom;
		box->h = env->zoom;
		drawbox(box, env);
		dickbutt = dickbutt->next;
	}
}
