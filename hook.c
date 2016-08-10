/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:27:37 by pfichepo          #+#    #+#             */
/*   Updated: 2016/08/10 14:54:34 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wtd.h"
#include "minilibx_macos/mlx.h"
#include <stdio.h>

int worldmap2[MAPWIDTH][MAPHEIGHT] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

static int		check_rot(t_env *env)
{
	double		rd;
	double		olddirx;
	double		oldplanex;

	olddirx = env->dirx;
	oldplanex = env->planex;
	rd = env->frametime * 1.0;
	if (env->right)
	{
		env->dirx = env->dirx * cos(-rd) - env->diry * sin(-rd);
		env->diry = olddirx * sin(-rd) + env->diry * cos(-rd);
		env->planex = env->planex * cos(-rd) - env->planey * sin(-rd);
		env->planey = oldplanex * sin(-rd) + env->planey * cos(-rd);
		return (1);
	}
	if (env->left)
	{
		env->dirx = env->dirx * cos(rd) - env->diry * sin(rd);
		env->diry = olddirx * sin(rd) + env->diry * cos(rd);
		env->planex = env->planex * cos(rd) - env->planey * sin(rd);
		env->planey = oldplanex * sin(rd) + env->planey * cos(rd);
		return (1);
	}
	return (0);
}

static int		check_move(t_env *env)
{
	double	md;

	md = env->frametime * 5.0;
	if (env->up)
	{
		if (worldmap2[(int)(env->posx + env->dirx * md)][(int)(env->posy)] == 0)
			env->posx += env->dirx * md;
		if (worldmap2[(int)(env->posx)][(int)(env->posy + env->diry *
		md)] == 0)
			env->posy += env->diry * md;
		return (1);
	}
	if (env->down)
	{
		if (worldmap2[(int)(env->posx - env->dirx * md)][(int)(env->posy)] == 0)
			env->posx -= env->dirx * md;
		if (worldmap2[(int)(env->posx)][(int)(env->posy - env->diry *
		md)] == 0)
			env->posy -= env->diry * md;
		return (1);
	}
	return (0);
}

int			hook_loop(t_env *env)
{
	if (env->posx < 0 || env->posy < 0 || env->posx > MAPWIDTH
		|| env->posy > MAPHEIGHT)
	{
		env->posx = 22;
		env->posy = 12;
	}
	if (check_move(env) + check_rot(env) != 0)
		draw(env);
	return (1);
}

int			key_press(int keycode, t_env *env)
{
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

int			key_release(int keycode, t_env *env)
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

int			fastmlx_pixel_put(t_env *env, int x, int y, int color)
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
