/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcextmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:38:59 by pfichepo          #+#    #+#             */
/*   Updated: 2016/03/12 18:39:00 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "minilibx_macos/mlx.h"

static void		drawmap(t_env *env)
{
	t_point	*dickbutt;
	t_point	*dickbutt2;
	int		i;

	dickbutt = env->grid;
	while (dickbutt != NULL)
	{
		i = 0;
		dickbutt2 = dickbutt;
		if (dickbutt->x + 1 != env->mapx)
			fdf_putline(env, dickbutt, dickbutt->next);
		if (dickbutt->y + 1 != env->mapy)
		{
			while (i < env->mapx)
			{
				dickbutt2 = dickbutt2->next;
				i++;
			}
			fdf_putline(env, dickbutt, dickbutt2);
			fdf_putline(env, dickbutt2, dickbutt);
		}
		dickbutt = dickbutt->next;
	}
}

static void		drawgrid(t_env *env)
{
	int x;
	int y;

	x = 0;
	while (x < env->w)
	{
		y = 0;
		while (y < env->h)
		{
			fastmlx_pixel_put(env, x, y, 0x00FFFF);
			y = y + 100;
		}
		x = x + 100;
	}
}

int				draw(t_env *env)
{
	if (!env->mlx)
		error("MLX IS NULL");
	mlx_clear_window(env->mlx, env->win);
	ft_putstr("Cleared\n");
	drawgrid(env);
	drawmap(env);
	return (1);
}

static void		lastopgoodsize(t_env *env)
{
	t_point *size;

	ft_transform2d(env);
	size = mapmin(env);
	env->offsetx = -(size->x);
	env->offsety = -(size->y);
	ft_transform2d(env);
	size = mapmax(env);
	env->offsetx = env->offsetx + (env->w - size->x) / 2;
	env->offsety = env->offsety + (env->h - size->y) / 2;
	ft_transform2d(env);

	t_point *d = env->grid;
	while (d)
	{
		printf("X: %i Y: %i\n", d->x_2d, d->y_2d);
		d = d ->next;
	}
	printf("FACTOR: %f\n", env->factor);
}

void			goodsize(t_env *env)
{
	t_point	*size;
	int		old;

	old = env->factor;
	ft_transform2d(env);
	while (1)
	{
		size = mapsize(env);
		if (((env->w - size->x) < 0) || ((env->h - size->y) < 0))
		{
			if (old == 0.002)
				errornohalt("Can't find good size");
			env->factor = old;
			break ;
		}
		if (((env->w - size->x) < 100) || ((env->h - size->y) < 100))
			break ;
		old = env->factor;
		env->factor += 0.0001;
		ft_transform2d(env);
	}
	lastopgoodsize(env);
}
