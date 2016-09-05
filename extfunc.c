/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 09:02:05 by pfichepo          #+#    #+#             */
/*   Updated: 2016/09/05 09:20:08 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wtd.h"

unsigned long	creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void			draw2dpt0(t_env *env, t_w3d *w3d)
{
	w3d->camerax = 2 * w3d->x / (double)(env->w) - 1;
	w3d->rayposx = env->posx;
	w3d->rayposy = env->posy;
	w3d->raydirx = env->dirx + env->planex * w3d->camerax;
	w3d->raydiry = env->diry + env->planey * w3d->camerax;
	w3d->mapx = (int)(w3d->rayposx);
	w3d->mapy = (int)(w3d->rayposy);
	w3d->deltadistx = sqrt(1 + (w3d->raydiry * w3d->raydiry) /
		(w3d->raydirx * w3d->raydirx));
	w3d->deltadisty = sqrt(1 + (w3d->raydirx * w3d->raydirx) /
		(w3d->raydiry * w3d->raydiry));
	w3d->hit = 0;
}

void			draw2dpt1(t_w3d *w3d)
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

void			draw2dpt2(t_w3d *w3d, t_env *env)
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
		if (env->map[w3d->mapx][w3d->mapy] > 0)
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

void			draw2dpt3(t_w3d *w3d, t_env *env)
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
