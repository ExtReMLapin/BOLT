/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcextmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:38:59 by pfichepo          #+#    #+#             */
/*   Updated: 2016/09/05 09:19:45 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wtd.h"
#include "minilibx_macos/mlx.h"

static void			verline(t_env *env)
{
	int		i;
	int		tmp;
	t_w3d	*w3d;

	w3d = env->w3d;
	if (w3d->drawend < w3d->drawstart)
	{
		tmp = w3d->drawstart;
		w3d->drawstart = w3d->drawend;
		w3d->drawend = tmp;
	}
	i = 0;
	while (i < (w3d->drawend - w3d->drawstart))
	{
		fastmlx_pixel_put(env, w3d->x, w3d->drawstart + i, w3d->color);
		i++;
	}
}

static int			clr(t_env *env)
{
	t_w3d *w3d;

	w3d = env->w3d;
	if (w3d->side == 0 && w3d->stepx >= 0)
		return (0xff0000);
	else if (w3d->side == 0 && w3d->stepx < 0)
		return (0x00ff00);
	else if (w3d->side == 1 && w3d->stepy >= 0)
		return (0x0000ff);
	else
		return (0xffffff);
}

static void			draw2d(t_env *env)
{
	t_w3d	*w3d;
	int		i2;
	double	col;

	w3d = env->w3d;
	w3d->x = 0;
	while (w3d->x < env->w)
	{
		draw2dpt0(env, w3d);
		draw2dpt1(w3d);
		draw2dpt2(w3d, env);
		draw2dpt3(w3d, env);
		w3d->color = clr(env);
		if (w3d->side == 1)
			w3d->color = w3d->color / 2;
		verline(env);
		w3d->x++;
	}
	i2 = 10;
	while (i2 < (1 / env->frametime) + 10)
	{
		col = (double)i2 / 60;
		verlineex(env, i2, hsv(col));
		i2++;
	}
}

int					draw(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	while (x < env->w)
	{
		y = 0;
		while (y < env->h)
		{
			if (y < env->h / 2)
				fastmlx_pixel_put(env, x, y, 0x7eC0ee);
			else
				fastmlx_pixel_put(env, x, y, 0x111111);
			y++;
		}
		x++;
	}
	draw2d(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	env->oldtime = env->time;
	env->time = clock();
	env->frametime = ((double)(env->time - env->oldtime) / CLOCKS_PER_SEC);
	return (1);
}
