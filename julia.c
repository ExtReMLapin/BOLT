/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:18:44 by pfichepo          #+#    #+#             */
/*   Updated: 2016/01/14 13:18:47 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

static t_julia		*init_ju(t_julia *ja, t_env *env)
{
	ja->h = env->h;
	ja->w = env->w;
	ja->y = 0;
	return (ja);
}

static	void		resetloop(t_julia *ja, t_env *e)
{
	ja->nr = 1.5 * (ja->x - ja->w / 2) / (0.5 * e->zm * ja->w) + e->ox;
	ja->ni = (ja->y - ja->h / 2) / (0.5 * e->zm * ja->h) + e->oy;
	ja->i = 0;
}

void				drawjulia(t_env *e)
{
	t_julia *ja;

	ja = e->ja;
	init_ju(ja, e);
	while (ja->y < ja->h)
	{
		ja->x = 0;
		while (ja->x < ja->w)
		{
			resetloop(ja, e);
			while (ja->i < e->maxiterations)
			{
				ja->orr = ja->nr;
				ja->oi = ja->ni;
				ja->nr = ja->orr * ja->orr - ja->oi * ja->oi + e->cre;
				ja->ni = 2 * ja->orr * ja->oi + e->cim;
				if ((ja->nr * ja->nr + ja->ni * ja->ni) > 4)
					break ;
				(ja->i)++;
			}
			fastmlx_pixel_put(e, ja->x++, ja->y, hsv(ja->i % 256, e, ja->i));
		}
		(ja->y)++;
	}
}
