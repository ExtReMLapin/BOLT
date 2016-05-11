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

static unsigned int	hsv(double v, t_env *env, int i)
{
	t_hsv	hsv;

	if (i >= env->maxIterations)
		return (0x000000);
	hsv.i = floor(v / 60);
	hsv.f = (v / 60) - hsv.i;
	hsv.l = v * (1 - v);
	hsv.m = v * (1 - hsv.f * v);
	hsv.n = v * (1 - (1 - hsv.f) * v);
	hsv.l *= 255;
	hsv.m *= 255;
	hsv.n *= 255;
	v *= 255;
	if (hsv.i == 0)
		return (((int)v << 16) + ((int)hsv.n << 8) + (int)hsv.l);
	else if (hsv.i == 1)
		return (((int)hsv.m << 16) + ((int)v << 8) + (int)hsv.l);
	else if (hsv.i == 2)
		return (((int)hsv.l << 16) + ((int)v << 8) + (int)hsv.n);
	else if (hsv.i == 3)
		return (((int)hsv.l << 16) + ((int)hsv.m << 8) + (int)v);
	else if (hsv.i == 4)
		return (((int)hsv.n << 16) + ((int)hsv.l << 8) + (int)v);
	else
		return (((int)v << 16) + ((int)hsv.l << 8) + (int)hsv.m);
}

static t_julia		*init_ju(t_julia *ja, t_env *env)
{
	ja->h = env->h;
	ja->w = env->w;
	ja->y = 0;
	return (ja);
}

static	void		resetloop(t_julia *ja, t_env *e)
{
	ja->nR = 1.5 * (ja->x - ja->w / 2) / (0.5 * e->zm * ja->w) + e->ox;
	ja->nI = (ja->y - ja->h / 2) / (0.5 * e->zm * ja->h) + e->oy;
	ja->i = 0;
}

static void			drawmap3d(t_env *e)
{
	t_julia *ja;

	ja = (t_julia*)malloc(sizeof(t_julia));
	init_ju((t_julia*)ja, e);
	while (ja->y < ja->h)
	{
		ja->x = 0;
		while (ja->x < ja->w)
		{
			resetloop(ja, e);
			while (ja->i < e->maxIterations)
			{
				ja->oR = ja->nR;
				ja->oI = ja->nI;
				ja->nR = ja->oR * ja->oR - ja->oI * ja->oI + e->cRe;
				ja->nI = 2 * ja->oR * ja->oI + e->cIm;
				if ((ja->nR * ja->nR + ja->nI * ja->nI) > 4)
					break ;
				(ja->i)++;
			}
			fastmlx_pixel_put(e, ja->x++, ja->y, hsv(ja->i % 256, e, ja->i));
		}
		(ja->y)++;
	}
}

int					draw(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	drawmap3d(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (1);
}
