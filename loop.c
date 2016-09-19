/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 12:18:51 by pfichepo          #+#    #+#             */
/*   Updated: 2016/09/19 09:31:43 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "include/fdf.h"
#include <stdio.h>

int				close_hook(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit(EXIT_SUCCESS);
	return (1);
}

static int		randomcolor(t_env *env)
{
	int		rand1;
	int		rand2;
	int		rand3;
	double	fac;

	fac = ((double)(env->time - env->timestart) / CLOCKS_PER_SEC) * 5;
	rand1 = sin(fac * 0.7) * (255) / 2 + 255 / 2;
	rand2 = sin(fac * 1.1) * (255) / 2 + 255 / 2;
	rand3 = sin(fac * 3) * (255) / 2 + 255 / 2;
	return (creatergb(rand1, rand2, rand3));
}

int				hook_loop(t_env *env)
{
	if (env->down)
		movething(env, 'y', 1);
	if (env->up)
		movething(env, 'y', -1);
	if (env->left)
		movething(env, 'x', -1);
	if (env->right)
		movething(env, 'x', 1);
	if (env->spkey)
		env->c = randomcolor(env);
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
	if (keycode == KEY_SPACE)
		env->spkey = 1;
	if (keycode == 53)
		close_hook(env);
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
	if (keycode == KEY_SPACE)
		env->spkey = 0;
	if (keycode == 82)
	{
		if (env->rendermode == 3)
			env->rendermode = 2;
		else
			env->rendermode = 3;
		draw(env);
	}
	return (1);
}
