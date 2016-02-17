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

	t_point *a = (t_point *)malloc(sizeof(t_point));
	t_point *b = (t_point *)malloc(sizeof(t_point));

	a->x_2d = 500;
	a->y_2d = 10;

	b->x_2d = 12;
	b->y_2d = 100;
	fdf_putline(a,b, env);
	while (dickbutt != NULL)
	{
		ft_transform2d(dickbutt, env);
		mlx_pixel_put(env->mlx, env->win, dickbutt->x_2d, dickbutt->y_2d , createRGB(dickbutt->z * 10,dickbutt->z * 10,dickbutt->z * 10));
		//drawbox(dickbutt->x * env->zoom, dickbutt->y * env->zoom, env->zoom, env->zoom, createRGB(dickbutt->z * 10,dickbutt->z * 10,dickbutt->z * 10), env);
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
	env->zoom = 5;
	env->h = 1080;
	env->w = 1920;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->w, env->h, "FdF");
	env->img = mlx_new_image(env->mlx, env->w, env->h);
	char **tbl =file_totbl(file) ;
	tbl = cleartbl(tbl);
	int **itbl = charrtointt(tbl);
	reallocint(itbl);
	t_point *pts = chrrtocor(itbl);
	env->grid = pts;
	env->factor = 0.3;

}

int main(int agc, char** argc)
{
	t_env *env;


	if (agc != 2)
		error("only one argument is allowed");

	env = (t_env *)malloc(sizeof(t_env));
	initenv(env, argc[1]);
	ft_putstr("Inited\n");
	mlx_expose_hook(env->win, draw, env);

	mlx_loop(env->mlx);
	exit(1);
	return (1);
}
