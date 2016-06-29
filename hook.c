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
#include <stdio.h>


int					hookkey(int keycode, t_env *env)
{
	keycode = keycode;
	draw(env);
	return (0);
}

int					mousekey(int x, int y, t_env *env)
{
	x = x;
	y = y;
	draw(env);
	return (1);
}

int					mousebutton(int button, int x, int y, t_env *env)
{
	x = x;
	y = y;
	button = button;
	*env = *env;
	return (1);
}

inline int			fastmlx_pixel_put(t_env *env, int x, int y, int color)
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
