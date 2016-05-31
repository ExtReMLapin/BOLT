/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:38:59 by pfichepo          #+#    #+#             */
/*   Updated: 2016/03/12 18:39:00 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

static t_mandel		*init_md(t_mandel *ja, t_env *env)
{
	ja->h = env->h;
	ja->w = env->w;
	ja->y = 0;
	return (ja);
}

static	void		resetloop(t_mandel *ja, t_env *env)
{
	ja->pr = 1.5 * (ja->x - ja->w / 2) / (0.5 * env->zm * ja->w) + env->ox - .5;
	ja->pi = (ja->y - ja->h / 2) / (0.5 * env->zm * ja->h) + env->oy;
	ja->nre = 0;
	ja->ni = 0;
	ja->ore = 0;
	ja->oi = 0;
	ja->i = 0;
}

void				drawmend(t_env *e)
{
	t_mandel *ja;

	ja = e->md;
	init_md(ja, e);
	while (ja->y < ja->h)
	{
		ja->x = 0;
		while (ja->x < ja->w)
		{
			resetloop(ja, e);
			while (ja->i < e->maxiterations)
			{
				ja->ore = ja->nre;
				ja->oi = ja->ni;
				ja->nre = ja->ore * ja->ore - ja->oi * ja->oi + ja->pr;
				ja->ni = 2 * ja->ore * ja->oi + ja->pi;
				if ((ja->nre * ja->nre + ja->ni * ja->ni) > 4)
					break ;
				(ja->i)++;
			}
			fastmlx_pixel_put(e, ja->x++, ja->y, hsv(ja->i % 256, e, ja->i));
		}
		(ja->y)++;
	}
}
