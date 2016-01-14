/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:18:44 by pfichepo          #+#    #+#             */
/*   Updated: 2016/01/14 13:18:47 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "minilibx_macos/mlx.h"

unsigned long createRGB(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

/**
*** Clang does optimize the operation, maybe with spacial ASM instruction, 
*** that's why i don't do operation like => or =< to check if in coords,
*** i just resie the box first
**/


void drawbox(int x , int y, int w, int h, int c, t_env *env)
{
	int i;
	int b;

	i = 0;
	y--;
	x++;
	w = w + 2;
	h = h + 2;
	while (i < env->h)
	{
		b = 0;
		while (b < env->w)
		{
			if (((i > y) && (i < (y+h))) && ((b > x ) && (b < (x + w))))
				mlx_pixel_put(env->mlx, env->win, b, i, c);
			b++;
		}
		i++;
	}
}