/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:27:37 by pfichepo          #+#    #+#             */
/*   Updated: 2016/09/14 13:21:04 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "minilibx_macos/mlx.h"

void				movething(t_env *env, char c, int dest)
{
	t_point		*pts;
	double		fac;

	fac = 1000*env->frametime;
	pts = env->grid;
	while (pts)
	{
		if (c == 'y')
			pts->y_2d += dest * fac;
		if (c == 'x')
			pts->x_2d += dest * fac;
		pts = pts->next;
	}
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
