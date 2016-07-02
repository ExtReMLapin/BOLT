/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:07:38 by pfichepo          #+#    #+#             */
/*   Updated: 2016/01/11 17:07:41 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "minilibx_macos/mlx.h"
#include <stdio.h>

unsigned long		creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static int					envint(t_env *env)
{
	env->w = 1600;
	env->h = 900;
	env->posX = 22; //x and y start position
	env->posY = 12;
	env->dirX = -1;
	env->dirY = 0; //initial direction vector
	env->planeX = 0;
	env->planeY = 0.66; //the 2d raycaster version of camera plane				
	env->time = clock(); //time of current frame
	env->oldtime = clock(); //time of previous frame
	env->frametime = 1;
	env->up = 0;
	env->down = 0;
	env->left = 0;
	env->right = 0;
	return (1);
}

static void					checkmlx(t_env *env)
{
	env->mlx = mlx_init();
	if (!(env->mlx))
		error("FAILED TO INIT MLX/MAYBE LINKING TO X11 SERVER");
	env->win = mlx_new_window(env->mlx, env->w, env->h, "nVishit FLEX DEMO BUILD #4351 [JUL-2016]");
	if (!(env->win))
		error("FAILED TO CREATE X11 WINDOW");
	env->img = mlx_new_image(env->mlx, env->w, env->h);
	if (!(env->img))
		error("FAILED TO CREATE IMG");
	env->data = mlx_get_data_addr(env->img, &env->bpp, \
		&env->size_line, &env->endian);
}

static void					initenv(t_env *env)
{
		envint(env);
		checkmlx(env);
}

int							main(void)
{
	t_env *env;

	env = (t_env *)malloc(sizeof(t_env));
	env->w3d = (t_w3d *)malloc(sizeof(t_w3d));

	initenv(env);
	mlx_expose_hook(env->win, draw, env);
	mlx_hook(env->win, 2, (1L << 0), key_press, env);
	mlx_hook(env->win, 3, (1L << 1), key_release, env);
	mlx_hook(env->win, 6, 64, mousekey, env);
	mlx_mouse_hook(env->win, mousebutton, env);
	mlx_loop_hook(env->mlx, hook_loop, env);
	mlx_do_key_autorepeatoff(env->mlx);
	mlx_loop(env->mlx);
	exit(1);
	return (1);
}
