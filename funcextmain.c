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

#include "include/wtd.h"
#include "minilibx_macos/mlx.h"
#include <stdio.h>

static void	verline(t_env *env)
{
	int i;
	int tmp;
	t_w3d *w3d;

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

int worldMap[MAPWIDTH][MAPHEIGHT]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

static void		draw2dpt0(t_env *env, t_w3d *w3d)
{
	w3d->camerax = 2 * w3d->x / (double)(env->w) - 1;
	w3d->rayposx = env->posx;
	w3d->rayposy = env->posy;
	w3d->raydirx = env->dirx + env->planex * w3d->camerax;
	w3d->raydiry = env->diry + env->planey * w3d->camerax;
	w3d->mapx = (int)(w3d->rayposx);
	w3d->mapy = (int)(w3d->rayposy);
	w3d->deltadistx = sqrt(1 + (w3d->raydiry * w3d->raydiry) / (w3d->raydirx * w3d->raydirx));
	w3d->deltadisty = sqrt(1 + (w3d->raydirx * w3d->raydirx) / (w3d->raydiry * w3d->raydiry));
	w3d->hit = 0;
}

static void		draw2dpt1(t_w3d *w3d)
{
	if (w3d->raydirx < 0)
	{
		w3d->stepx = -1;
		w3d->sidedistx = (w3d->rayposx - w3d->mapx) * w3d->deltadistx;
	}
	else
	{
		w3d->stepx = 1;
		w3d->sidedistx = (w3d->mapx + 1.0 - w3d->rayposx) * w3d->deltadistx;
	}
	if (w3d->raydiry < 0)
	{
		w3d->stepy = -1;
		w3d->sidedisty = (w3d->rayposy - w3d->mapy) * w3d->deltadisty;
	}
	else
	{
		w3d->stepy = 1;
		w3d->sidedisty = (w3d->mapy + 1.0 - w3d->rayposy) * w3d->deltadisty;
	}
}

static void		draw2dpt2(t_w3d *w3d, t_env *env)
{
	while (w3d->hit == 0)
	{
		if (w3d->sidedistx < w3d->sidedisty)
		{
			w3d->sidedistx += w3d->deltadistx;
			w3d->mapx += w3d->stepx;
			w3d->side = 0;
		}
		else
		{
			w3d->sidedisty += w3d->deltadisty;
			w3d->mapy += w3d->stepy;
			w3d->side = 1;
		}
		if (worldMap[w3d->mapx][w3d->mapy] > 0)
			w3d->hit = 1;
	}
	if (w3d->side == 0)
		w3d->perpwalldist = (w3d->mapx - w3d->rayposx + (1 - w3d->stepx) / 2) /
	w3d->raydirx;
	else
		w3d->perpwalldist = (w3d->mapy - w3d->rayposy + (1 - w3d->stepy) / 2) /
	w3d->raydiry;
	w3d->lineheight = (int)(env->h / w3d->perpwalldist);
	w3d->drawstart = -(w3d->lineheight) / 2 + env->h / 2;
}

static void		draw2dpt3(t_w3d *w3d, t_env *env)
{
	if (w3d->drawstart < 0)
		w3d->drawstart = 0;
	if (w3d->side == 0)
		w3d->perpwalldist = (w3d->mapx - w3d->rayposx +
		(1 - w3d->stepx) / 2) / w3d->raydirx;
	else
		w3d->perpwalldist = (w3d->mapy - w3d->rayposy +
		(1 - w3d->stepy) / 2) / w3d->raydiry;
	w3d->lineheight = (int)(env->h / w3d->perpwalldist);
	w3d->drawstart = -(w3d->lineheight) / 2 + env->h / 2;
	if (w3d->drawstart < 0)
		w3d->drawstart = 0;
	w3d->drawend = w3d->lineheight / 2 + env->h / 2;
	if (w3d->drawend >= env->h)
		w3d->drawend = env->h - 1;
}

static int		clr(t_env *env)
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

static void		draw2d(t_env *env)
{
	t_w3d	*w3d;
	int i2;
	double col;

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
	while (i2 < (1/env->frametime)+10)
	{
		col = (double)i2/60;
		verlineex(env, i2, hsv(col));
		i2++;
	}
}

int				draw(t_env *env)
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
