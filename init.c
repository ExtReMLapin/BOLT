/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:07:38 by pfichepo          #+#    #+#             */
/*   Updated: 2016/09/05 11:36:41 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wtd.h"
#include "minilibx_macos/mlx.h"

static int					envint(t_env *env)
{
	env->w = 1600;
	env->h = 900;
	env->posx = 5;
	env->posy = 5;
	env->dirx = -1;
	env->diry = 0;
	env->planex = 0;
	env->planey = 0.66;
	env->time = clock();
	env->oldtime = clock();
	env->frametime = 1;
	env->up = 0;
	env->down = 0;
	env->left = 0;
	env->right = 0;
	emptymap(env);
	return (1);
}

void						verlineex(t_env *env, int x, int col)
{
	int i;
	int y1;
	int y2;

	y1 = 20;
	y2 = 50;
	i = 0;
	while (i < (y2 - y1))
	{
		fastmlx_pixel_put(env, x, y1 + i, col);
		i++;
	}
}

static void					checkmlx(t_env *env)
{
	env->mlx = mlx_init();
	if (!(env->mlx))
		error("FAILED TO INIT MLX/MAYBE LINKING TO X11 SERVER");
	env->win = mlx_new_window(env->mlx, env->w, env->h, "Wolf3D");
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
	mlx_hook(env->win, 17, (1L << 17), close_hook, env);
	mlx_loop_hook(env->mlx, hook_loop, env);
	mlx_do_key_autorepeatoff(env->mlx);
	mlx_loop(env->mlx);
	exit(1);
	return (1);
}
