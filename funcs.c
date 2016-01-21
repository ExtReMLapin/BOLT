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

void drawbox(int x , int y, int w, int h, int c, t_env *env)
{
	int i;
	int i2;
	int b;
	int b2;

	i = 0;
	while (w > i)
	{
		i2 = x+i;
		b = 0;
		while (h > b)
		{
			b2 = y+b;
			mlx_pixel_put(env->mlx, env->win, i2, b2, c);
			b++;
		}	
		i++;
	}
}
