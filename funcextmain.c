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
# include <SDL/SDL.h>


static void verLine(int x, int y1, int y2, int color, t_env *env)
{
	int i;
	int tmp;

	if (y2 < y1)
	{
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}
	i = 0;
	while (i < (y2 - y1))
	{
		fastmlx_pixel_put(env,x, y1+i,color);
		i++;
	}
}

int worldMap[mapWidth][mapHeight]=
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

static void draw2dpt0(t_env *env, t_w3d *w3d)
{
	w3d->cameraX = 2 * w3d->x / (double)(env->w) - 1;
	w3d->rayPosX = env->posX ;
	w3d->rayPosY = env->posY;
	w3d->rayDirX = env->dirX + env->planeX * w3d->cameraX;
	w3d->rayDirY = env->dirY + env->planeY * w3d->cameraX;
	w3d->mapX = (int)(w3d->rayPosX);
}

static void draw2dpt1(t_w3d *w3d)
{
	w3d->mapY = (int)(w3d->rayPosY);
	w3d->deltaDistX = sqrt(1 + (w3d->rayDirY * w3d->rayDirY) / (w3d->rayDirX * w3d->rayDirX));
	w3d->deltaDistY = sqrt(1 + (w3d->rayDirX * w3d->rayDirX) / (w3d->rayDirY * w3d->rayDirY));
	w3d->hit = 0;
	if (w3d->rayDirX < 0)
	{
		w3d->stepX = -1;
		w3d->sideDistX = (w3d->rayPosX - w3d->mapX) * w3d->deltaDistX;
	}
	else
	{
		w3d->stepX = 1;
		w3d->sideDistX = (w3d->mapX + 1.0 - w3d->rayPosX) * w3d->deltaDistX;
	}
	if (w3d->rayDirY < 0)
	{
		w3d->stepY = -1;
		w3d->sideDistY = (w3d->rayPosY - w3d->mapY) * w3d->deltaDistY;
	}
	else
	{
		w3d->stepY = 1;
		w3d->sideDistY = (w3d->mapY + 1.0 - w3d->rayPosY) * w3d->deltaDistY;
	}
}

static void draw2dpt2( t_w3d *w3d, t_env *env)
{
	while (w3d->hit == 0)
	{
		if (w3d->sideDistX < w3d->sideDistY)
		{
			w3d->sideDistX += w3d->deltaDistX;
			w3d->mapX += w3d->stepX;
			w3d->side = 0;
		}
		else
		{
			w3d->sideDistY += w3d->deltaDistY;
			w3d->mapY += w3d->stepY;
			w3d->side = 1;
		}
		if (worldMap[w3d->mapX][w3d->mapY] > 0)
			w3d->hit = 1;
	}
	if (w3d->side == 0) 
			w3d->perpWallDist = (w3d->mapX - w3d->rayPosX + (1 - w3d->stepX) / 2) / w3d->rayDirX;
		else
			w3d->perpWallDist = (w3d->mapY - w3d->rayPosY + (1 - w3d->stepY) / 2) / w3d->rayDirY;
	w3d->lineHeight = (int)(env->h / w3d->perpWallDist);
	w3d->drawStart = -(w3d->lineHeight) / 2 + env->h / 2;
	if(w3d->drawStart < 0)
		w3d->drawStart = 0;
}

static void draw2dpt3( t_w3d *w3d, t_env *env)
{
	if (w3d->side == 0) 
			w3d->perpWallDist = (w3d->mapX - w3d->rayPosX + (1 - w3d->stepX) / 2) / w3d->rayDirX;
		else
			w3d->perpWallDist = (w3d->mapY - w3d->rayPosY + (1 - w3d->stepY) / 2) / w3d->rayDirY;
		w3d->lineHeight = (int)(env->h / w3d->perpWallDist);
		w3d->drawStart = -(w3d->lineHeight) / 2 + env->h / 2;
		if(w3d->drawStart < 0)
			w3d->drawStart = 0;
		w3d->drawEnd = w3d->lineHeight / 2 + env->h / 2;
		if(w3d->drawEnd >= env->h)
			w3d->drawEnd = env->h - 1;
}

static void draw2d(t_env *env)
{
	t_w3d *w3d = env->w3d;
	int clr[6] = {0xff0000,0x00ff00, 0x0000ff, 0x0000ff, 0xffff00};
	w3d->x = 0;
	while ( w3d->x < env->w) // tout pixel ecran
	{
		draw2dpt0(env, w3d);
		draw2dpt1(w3d);
		draw2dpt2(w3d, env);
		draw2dpt3(w3d, env);
		w3d->color = clr[(worldMap[w3d->mapX][w3d->mapY])-1];
		if (w3d->side == 1) 
			w3d->color = w3d->color / 2;
		verLine(w3d->x, w3d->drawStart, w3d->drawEnd, w3d->color, env);
		w3d->x++;
	}
}

int					draw(t_env *env)
{
	int x;
	int y;
	
	//mlx_clear_window(env->mlx, env->win);
	x = 0;
	while (x < env->w)
	{
		y = 0;
		while (y < env->h)
		{
			if (y < env->h/2)
				fastmlx_pixel_put(env, x , y , 0x7EC0EE);
			else
				fastmlx_pixel_put(env, x , y , 0x000000);
			y++;
		}
		x++;
	}
	draw2d(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	env->oldtime = env->time;
	env->time = clock();
	env->frametime =  ((double)(env->time - env->oldtime) / 1000000.00000000F ) * 1000; 
	return (1);
}
