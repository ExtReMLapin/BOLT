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


static void drawmap(t_env *env)
{
	t_point *dickbutt;
	dickbutt = env->grid;

	while (dickbutt != NULL)
	{
		if (dickbutt->x +1 != env->mapx)
			fdf_putline(env, dickbutt, dickbutt->next);

		fastmlx_pixel_put(env, dickbutt->x_2d, dickbutt->y_2d , createRGB(255,255,dickbutt->z * 10));
		dickbutt = dickbutt->next;
	}
}

static int draw(t_env *env)
{
	if (!env->mlx)
		error("MLX IS NULL");

	mlx_clear_window(env->mlx, env->win);
	ft_putstr("Cleared\n");
	drawmap(env);
	return (1);
}

static void initenv(t_env *env, char *file)
{
	ft_putstr("Initializing the env vars ... ");
	env->zoom = 5;
	env->h = 1080;
	env->w = 1920;
	char **tbl = file_totbl(file) ;
	tbl = cleartbl(tbl);
	int **itbl = charrtointt(tbl);
	reallocint(itbl);
	printintint(itbl);
	env->mapx = tblmax(itbl, 0);
	env->mapy = tblmax(itbl, 1);
	t_point *pts = chrrtocor(itbl);
	env->grid = pts;
	env->factor = 2;
	env->mlx = mlx_init();
	if (!(env->mlx))
		error("FAILED TO INIT MLX/MAYBE LINKING TO X11 SERVER");
	env->win = mlx_new_window(env->mlx, env->w, env->h, "FdF");
	if (!(env->mlx))
		error("FAILED TO CREATE X11 WINDOW");
	env->img = mlx_new_image(env->mlx, env->w, env->h);
	ft_putstr("Done !\n");

}

int main(int agc, char** argc)
{
	t_env *env;


	if (agc != 2)
		error("only one argument is allowed");

	env = (t_env *)malloc(sizeof(t_env));
	initenv(env, argc[1]);
	ft_transform2d(env);

	mlx_expose_hook(env->win, draw, env);

	mlx_loop(env->mlx);
	exit(1);
	return (1);
}
