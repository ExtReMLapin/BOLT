/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 08:31:07 by pfichepo          #+#    #+#             */
/*   Updated: 2016/09/05 13:21:02 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wtd.h"
#include "minilibx_macos/mlx.h"

int				close_hook(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
}

int				fastmlx_pixel_put(t_env *env, int x, int y, int color)
{
	int h;
	int w;
	int off;

	h = env->h;
	w = env->w;
	if ((x > w) || (x < 0))
		return (0);
	if ((y > h) || (y < 0))
		return (0);
	off = (x * 4) + (env->size_line * y);
	*(unsigned int*)(env->data + off) = mlx_get_color_value(env->mlx, color);
	return (1);
}

static void		mapext(t_env *env)
{
	env->map[10][10] = 1;
	env->map[10][12] = 1;
	env->map[11][11] = 1;
	env->map[10][11] = 1;
}

static void		mallocmap(t_env *env)
{
	int i;

	i = 0;
	env->map = (int**)malloc(sizeof(int*) * MAPHEIGHT);
	while (i < MAPHEIGHT)
	{
		env->map[i] = (int*)malloc(sizeof(int) * MAPWIDTH);
		i++;
	}
}

void			emptymap(t_env *env)
{
	int i;
	int i2;
	int var;

	mallocmap(env);
	i = 0;
	while (i < MAPWIDTH)
	{
		i2 = 0;
		while (i2 < MAPHEIGHT)
		{
			if (i == 0 || i == MAPWIDTH - 1 || i2 == 0 || i2 == MAPHEIGHT - 1)
				var = 1;
			else
				var = 0;
			env->map[i][i2] = var;
			i2++;
		}
		i++;
	}
	mapext(env);
}
