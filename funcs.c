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

unsigned long		creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void				drawbox(t_box *box, t_env *env)
{
	int i;
	int i2;
	int b;
	int b2;

	i = 0;
	while (box->w > i)
	{
		i2 = box->x + i;
		b = 0;
		while (box->h > b)
		{
			b2 = box->y + b;
			fastmlx_pixel_put(env, i2, b2, box->c);
			b++;
		}
		i++;
	}
}