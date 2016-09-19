/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:27:37 by pfichepo          #+#    #+#             */
/*   Updated: 2016/09/19 09:29:54 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "minilibx_macos/mlx.h"

void				movething(t_env *env, char c, int dest)
{
	t_point		*pts;
	double		fac;

	fac = 15;
	pts = env->grid;
	while (pts)
	{
		if (c == 'y')
			pts->y_2d = pts->y_2d + (dest * fac);
		if (c == 'x')
			pts->x_2d = pts->x_2d + (dest * fac);
		pts = pts->next;
	}
}

inline int			fastmlx_pixel_put(t_env *env, int x, int y, int color)
{
	int h;
	int w;

	h = env->h;
	w = env->w;
	if ((y < 0) || (x < 0))
		return (0);
	if ((y + 1 > h) || (x + 1 > w))
		return (0);
	*(unsigned int*)(env->data + (x * 4) + (env->size_line * y)) = color;
	return (1);
}
