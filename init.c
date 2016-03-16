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

static void		envint(t_env *env)
{
	env->h = 1080;
	env->w = 1920;
	env->offsetx = 0;
	env->offsety = 0;
	env->factor = 0.01;
	env->rendermode = 2;
	env->zoom = 1;
}

static void		checkmlx(t_env *env)
{
	env->mlx = mlx_init();
	if (!(env->mlx))
		error("FAILED TO INIT MLX/MAYBE LINKING TO X11 SERVER");
	env->win = mlx_new_window(env->mlx, env->w, env->h, "FdF");
	if (!(env->mlx))
		error("FAILED TO CREATE X11 WINDOW");
}

static void		initenv(t_env *env, char *file)
{
	int			**itbl;
	char		**tbl;
	t_point		*pts;

	env->timestart = clock();
	checkread(file);
	envint(env);
	checkmlx(env);
	tbl = file_totbl(file);
	tbl = cleartbl(tbl);
	itbl = charrtointt(tbl);
	reallocint(itbl);
	if (!(itbl[0]))
		error("CAN'T READ FILE CONTENT, MAY BE TOO BIG");
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
		error("Only one argument is allowed, and it has to be a file");
	env = (t_env *)malloc(sizeof(t_env));
	initenv(env, argc[1]);
	mlx_expose_hook(env->win, draw, env);
	mlx_key_hook(env->win, hookkey, env);
	mlx_loop(env->mlx);
	exit(1);
	return (1);
}
