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

static void initenv(t_env *env, char *file)
{
	env->zoom = 10;
	env->h = 1080;
	env->w = 1920;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->w, env->h, "eheh");
	env->grid = chrrtocor(reallocint(charrtointt(cleartbl(file_totbl(file)))));
}


int main(int agc, char** argc)
{
	t_env *env;
	t_point *dickbutt;

	if (agc != 2)
		error("only one argument is allowed");

	env = (t_env *)malloc(sizeof(t_env));
	initenv(env, argc[1]);
	ft_putstr("Inited\n");
	dickbutt = env->grid;
	while (dickbutt != NULL)
	{
		//mlx_pixel_put(env->mlx, env->win, dickbutt->x * env->zoom, dickbutt->y * env->zoom, createRGB(dickbutt->z * 10,dickbutt->z * 10,dickbutt->z * 10));
		drawbox(dickbutt->x * env->zoom, dickbutt->y * env->zoom, env->zoom, env->zoom, createRGB(dickbutt->z * 10,dickbutt->z * 10,dickbutt->z * 10), env);
		dickbutt = dickbutt->next;
	}
	mlx_loop(env->mlx);
	while (1)
	{}

	return (1);
}