/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:27:37 by pfichepo          #+#    #+#             */
/*   Updated: 2016/09/05 13:20:51 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wtd.h"
#include "minilibx_macos/mlx.h"

static int		check_rot(t_env *env)
{
	double		rd;
	double		olddirx;
	double		oldplanex;

	olddirx = env->dirx;
	oldplanex = env->planex;
	rd = env->frametime * 3.0;
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
	return (1);
}

static int		check_move(t_env *env)
{
	double	md;

	md = env->frametime * 5.0;
	if (env->up)
	{
		if (env->map[(int)(env->posx + env->dirx * md)][(int)(env->posy)] == 0)
			env->posx += env->dirx * md;
		if (env->map[(int)(env->posx)][(int)(env->posy + env->diry *
		md)] == 0)
			env->posy += env->diry * md;
		return (1);
	}
	if (env->down)
	{
		if (env->map[(int)(env->posx - env->dirx * md)][(int)(env->posy)] == 0)
			env->posx -= env->dirx * md;
		if (env->map[(int)(env->posx)][(int)(env->posy - env->diry *
		md)] == 0)
			env->posy -= env->diry * md;
		return (1);
	}
	return (1);
}

int				hook_loop(t_env *env)
{
	if (env->posx < 0 || env->posy < 0 || env->posx > MAPWIDTH
		|| env->posy > MAPHEIGHT)
	{
		env->posx = 5;
		env->posy = 5;
	}
	if (check_move(env) + check_rot(env) != 0)
		draw(env);
	return (1);
}

int				key_press(int keycode, t_env *env)
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

int				key_release(int keycode, t_env *env)
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
