/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcextmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:38:59 by pfichepo          #+#    #+#             */
/*   Updated: 2016/03/12 18:39:00 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include "minilibx_macos/mlx.h"

static void		drawmap(t_env *env)
{
	t_point	*dickbutt;
	t_point	*dickbutt2;
	int		i;

	dickbutt = env->grid;
	while (dickbutt != NULL)
	{
		i = 0;
		dickbutt2 = dickbutt;
		if (dickbutt->x + 1 != env->mapx)
			fdf_putline(env, dickbutt, dickbutt->next);
		if (dickbutt->y + 1 != env->mapy)
		{
			while (i < env->mapx)
			{
				dickbutt2 = dickbutt2->next;
				i++;
			}
			fdf_putline(env, dickbutt, dickbutt2);
			fdf_putline(env, dickbutt2, dickbutt);
		}
		dickbutt = dickbutt->next;
	}
}

int				draw(t_env *env)
{
	if (!env->mlx)
		error("MLX IS NULL");
	mlx_clear_window(env->mlx, env->win);
	ft_putstr("Cleared\n");
	drawmap(env);
	return (1);
}

static void		lastopgoodsize(t_env *env)
{
	t_point *size;

	ft_transform2d(env);
	size = mapmin(env);
	env->offsetx = -(size->x);
	env->offsety = -(size->y);
	ft_transform2d(env);
}

void			goodsize(t_env *env)
{
	t_point	*size;
	int		old;

	old = env->factor;
	ft_transform2d(env);
	while (1)
	{
		size = mapsize(env);
		if (((env->w - size->x) < 0) || ((env->h - size->y) < 0))
		{
			if (old == 0.2)
				errornohalt("Can't find good size");
			env->factor = old;
			break ;
		}
		if (((env->w - size->x) < 100) || ((env->h - size->y) < 100))
			break ;
		old = env->factor;
		env->factor += 0.001;
		ft_transform2d(env);
	}
	lastopgoodsize(env);
}
