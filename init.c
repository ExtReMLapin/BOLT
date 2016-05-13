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

unsigned long inline		creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static void		envint(t_env *env)
{
	env->w = 800;
	env->h = 800;
	env->cIm = 0.27015;
	env->cRe = -0.7;
	env->ox = 0;
	env->oy = 0;
	env->zm = 1;
	env->ja = (t_julia*)malloc(sizeof(t_julia));
	env->md = (t_mandel*)malloc(sizeof(t_mandel));
}

static void		checkmlx(t_env *env)
{
	env->mlx = mlx_init();
	if (!(env->mlx))
		error("FAILED TO INIT MLX/MAYBE LINKING TO X11 SERVER");
	env->win = mlx_new_window(env->mlx, env->w, env->h, "FdF");
	if (!(env->win))
		error("FAILED TO CREATE X11 WINDOW");
	env->img = mlx_new_image(env->mlx, env->w, env->h);
	env->data = mlx_get_data_addr(env->img, &env->bpp, \
		&env->size_line, &env->endian);
}

static void		initenv(t_env *env)
{
	envint(env);
	checkmlx(env);
}

int				main()
{
	t_env *env;
	env = (t_env *)malloc(sizeof(t_env));
	initenv(env);
	mlx_expose_hook(env->win, draw, env);
	mlx_hook(env->win, 6, 64, mousekey, env);
	mlx_key_hook(env->win, hookkey, env);
	mlx_loop(env->mlx);
	exit(1);
	return (1);
}