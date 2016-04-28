/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:27:37 by pfichepo          #+#    #+#             */
/*   Updated: 2016/03/15 14:27:39 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "minilibx_macos/mlx.h"

static void			movething(t_env *env, char c, int dest)
{
	t_point		*pts;

	pts = env->grid;
	while (pts)
	{
		if (c == 'y')
			pts->y_2d += dest * 10;
		if (c == 'x')
			pts->x_2d += dest * 10;
		pts = pts->next;
	}
	draw(env);
}

static void			subcall(t_env *env, int keycode)
{
	if (keycode == 126)
		movething(env, 'y', -1);
	if (keycode == 125)
		movething(env, 'y', 1);
	if (keycode == 123)
		movething(env, 'x', -1);
	if (keycode == 124)
		movething(env, 'x', 1);
}

static int			randomcolor(void)
{
	int rand1;
	int rand2;
	int rand3;

	rand1 = rand() % 255 + 50;
	rand2 = rand() % 255 + 50;
	rand3 = rand() % 255 + 50;
	return (creatergb(rand1, rand2, rand3));
}

int					hookkey(int keycode, t_env *env)
{
	draw(env);
	return (1);
	subcall(env, keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(EXIT_SUCCESS);
		return (1);
	}
	if (keycode == 36)
	{
		if (env->rendermode == 3)
			env->rendermode = 2;
		else
			env->rendermode = 3;
		draw(env);
		return (1);
	}
	if (keycode == 49)
	{
		env->c = randomcolor();
		draw(env);
	}
	return (0);
}

int 				mousekey(int button, int x, int y, t_env *env )
{
	env->maxIterations = y;
	env->cRe = -(x/1000);
	env->cRe = -0.7;
	ft_putnbr(button);
	printf("X %i Y %i BUTTON %i\n", x, y, button);
	draw(env);
	return (1);
}

inline int			fastmlx_pixel_put(t_env *env, int x, int y, int color)
{
	int h;
	int w;

	h = env->h;
	w = env->w;
	if ((x > w) || (x < 0))
		return (0);
	if ((y > h) || (y < 0))
		return (0);
	*(unsigned int*)(env->data + (x * 4) + (env->size_line * y)) = mlx_get_color_value(env->mlx, color);
	return (1);
}
