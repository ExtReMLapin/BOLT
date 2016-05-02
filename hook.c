/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:27:37 by pfichepo          #+#    #+#             */
/*   Updated: 2016/03/15 14:27:39 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "minilibx_macos/mlx.h"


int					hookkey(int keycode, t_env *env)
{
	keycode = 1;
	env->w = env->w;
	return (0);
}

int 				mousekey( int x, int y, t_env *env )
{
	env->maxIterations = (y * 50) / env->h ;
	env->cIm =  -0.36 + ((double)x) * (0.36 + 0.36) / (double)env->w ;
	draw(env);
	return (1);
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
	*(unsigned int*)(env->data + (x * 4) + (env->size_line * y)) = mlx_get_color_value(env->mlx, color);
	return (1);
}

