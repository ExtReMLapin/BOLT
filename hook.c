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

int worldMap2[mapWidth][mapHeight]=
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


int hook_loop(t_env *env)
{
	int redo;
	double moveSpeed = env->frametime * 5.0;
	double rotSpeed = env->frametime * 1.0;
	redo = 0;
	if (env->right)
	{
		double oldDirX = env->dirX;
		env->dirX = env->dirX * cos(-rotSpeed) - env->dirY * sin(-rotSpeed);
		env->dirY = oldDirX * sin(-rotSpeed) + env->dirY * cos(-rotSpeed);
		double oldPlaneX = env->planeX;
		env->planeX = env->planeX * cos(-rotSpeed) - env->planeY * sin(-rotSpeed);
		env->planeY = oldPlaneX * sin(-rotSpeed) + env->planeY * cos(-rotSpeed);
		redo = 1;
	}
	if (env->left)
	{
		double oldDirX = env->dirX;
		env->dirX = env->dirX * cos(rotSpeed) - env->dirY * sin(rotSpeed);
		env->dirY = oldDirX * sin(rotSpeed) + env->dirY * cos(rotSpeed);
		double oldPlaneX = env->planeX;
		env->planeX = env->planeX * cos(rotSpeed) - env->planeY * sin(rotSpeed);
		env->planeY = oldPlaneX * sin(rotSpeed) + env->planeY * cos(rotSpeed);
		redo = 1;
	}
	if (env->up)
	{
		if(worldMap2[(int)(env->posX + env->dirX * moveSpeed)][(int)(env->posY)] == 0)
			env->posX += env->dirX * moveSpeed;
		if(worldMap2[(int)(env->posX)][(int)(env->posY + env->dirY * moveSpeed)] == 0) 
			env->posY += env->dirY * moveSpeed;
		redo = 1;
	}
	if (env->down)
	{
		if(worldMap2[(int)(env->posX - env->dirX * moveSpeed)][(int)(env->posY)] == 0)
			env->posX -= env->dirX * moveSpeed;
		if(worldMap2[(int)(env->posX)][(int)(env->posY - env->dirY * moveSpeed)] == 0) 
			env->posY -= env->dirY * moveSpeed;
		redo = 1;
	}
	if (redo)
		draw(env);
	return (1);
}

int key_press(int keycode, t_env *env)
{
	printf("%s\n","d" );
	if (keycode == KEY_RIGHT)
		env->right = 1;
	if (keycode == KEY_LEFT)
		env->left = 1;
	if (keycode == KEY_UP)
		env->up = 1;
	if (keycode == KEY_DOWN)
		env->down = 1;
	return (1);
}

int key_release(int keycode, t_env *env)
{
	if (keycode == KEY_RIGHT)
		env->right = 0;
	if (keycode == KEY_LEFT)
		env->left = 0;
	if (keycode == KEY_UP)
		env->up = 0;
	if (keycode == KEY_DOWN)
		env->down = 0;
	return (1);
}

int					mousekey(int x, int y, t_env *env)
{
	x = x;
	y = y;
	//draw(env);
	*env = *env;
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
