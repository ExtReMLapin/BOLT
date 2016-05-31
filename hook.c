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

#include "include/fractol.h"
#include "minilibx_macos/mlx.h"

static double		calczoomratio(t_env *env)
{
	return (1 / (env->zm * 10.0));
}

int					hookkey(int keycode, t_env *env)
{
	if (keycode == 69)
		env->zm = env->zm * 1.1;
	if (keycode == 78)
		env->zm = env->zm / 1.1;
	if (keycode == 126)
		env->oy = env->oy - calczoomratio(env);
	if (keycode == 125)
		env->oy = env->oy + calczoomratio(env);
	if (keycode == 123)
		env->ox = env->ox - calczoomratio(env);
	if (keycode == 124)
		env->ox = env->ox + calczoomratio(env);
	draw(env);
	return (0);
}

int					mousekey(int x, int y, t_env *env)
{
	env->maxIterations = (y * 50) / env->h;
	env->cIm = -0.36 + ((double)x) * (0.36 + 0.36) / (double)env->w;
	draw(env);
	return (1);
}

int					mousebutton(int button, int x, int y, t_env *env)
{
	double rtx;
	double rty;
	if (x < 0 || x > env->w || y < 0 || y > env->h)
		return (1);
	if (button == 1)
	{
		rtx = -0.5 + (double)x / (double)env->w;
		rty = -0.5 + (double)y / (double)env->h;
		env->ox = env->ox + (rtx / (env->zm * 2.0) * 5);
		env->oy = env->oy + (rty / (env->zm * 2.0) * 5);
	}
	if (button == 5)
		env->zm = env->zm / 1.1;
	if (button == 6)
		env->zm = env->zm * 1.1;
	draw(env);
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
