/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:07:38 by pfichepo          #+#    #+#             */
/*   Updated: 2016/09/15 10:12:46 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "minilibx_macos/mlx.h"

static void		envint(t_env *env)
{
	env->h = 1080;
	env->w = 1920;
	env->offsetx = 0;
	env->offsety = 0;
	env->factor = 0.01;
	env->rendermode = 3;
	env->zoom = 1;
	env->c = 0xFFFFFF;
	env->down = 0;
	env->up = 0;
	env->right = 0;
	env->left = 0;
	env->spkey = 0;
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

static void		initenv(t_env *env, char *file)
{
	int			**itbl;
	char		**tbl;
	t_point		*pts;

	env->timestart = clock();
	envint(env);
	checkread(file, env);
	checkmlx(env);
	tbl = file_totbl(file);
	tbl = cleartbl(tbl);
	itbl = charrtointt(tbl);
	reallocint(itbl);
	if (!(itbl[0]))
		error("CAN'T READ FILE CONTENT, MAY BE TOO BIG OR EMPTY");
	pts = chrrtocor(itbl);
	env->mapx = tblmax(itbl, 0);
	env->mapy = tblmax(itbl, 1);
	env->grid = pts;
	goodsize(env);
	mapsize2(env);
	calczoom(env);
	env->timeend = clock();
}

int				main(int agc, char **argc)
{
	t_env *env;

	if (agc != 2)
		error("ONLY ONE ARG IS ALLOWED AND IT HAS TO BE A FILE");
	env = (t_env *)malloc(sizeof(t_env));
	initenv(env, argc[1]);
	mlx_hook(env->win, 2, (1L << 0), key_press, env);
	mlx_hook(env->win, 3, (1L << 1), key_release, env);
	mlx_hook(env->win, 17, (1L << 17), close_hook, env);
	mlx_loop_hook(env->mlx, hook_loop, env);
	mlx_do_key_autorepeatoff(env->mlx);
	mlx_expose_hook(env->win, draw, env);
	mlx_loop(env->mlx);
	exit(1);
	return (1);
}
