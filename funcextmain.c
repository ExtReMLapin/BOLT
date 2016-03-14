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


static void		drawmap3d(t_env *env)
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

static void drawinfo(t_env *env)
{
	char buffer[255];
	char buffer2[255];
	double time1;
	double time2;

	time1 = (double)(clock() - env->time);
	time2 = (double)(env->timeend - env->timestart);
	mlx_string_put(env->mlx, env->win, 10, 10,0xFFFFFF, "Lines :");
	mlx_string_put(env->mlx, env->win, 85, 10,0xFFFFFF, ft_itoa(pointsnb(env->grid)));
	
	sprintf(buffer, "%.4f", time1/1000000);
	sprintf(buffer2, "%.3f", time2/1000000);
	mlx_string_put(env->mlx, env->win, 10, 40,0xFFFFFF, "Sec to calc draw :");
	mlx_string_put(env->mlx, env->win, 194, 40,0xFFFFFF, buffer);
	mlx_string_put(env->mlx, env->win, 10, 70,0xFFFFFF, "Sec to process file :");
	mlx_string_put(env->mlx, env->win, 230, 70,0xFFFFFF, buffer2);
}

int				draw(t_env *env)
{
	if (!env->mlx)
		error("MLX IS NULL");
	env->time = clock();
	mlx_clear_window(env->mlx, env->win);

	ft_putstr("Cleared\n");
	if (env->rendermode == 3)
		drawmap3d(env);
	else
		drawmap2d(env);
	drawinfo(env);

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
	size = mapmax(env);
	env->offsetx = env->offsetx + (env->w - size->x) / 2;
	env->offsety = env->offsety + (env->h - size->y) / 2;
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
			if (old == 0.002)
				errornohalt("Can't find good size");
			env->factor = old;
			break ;
		}
		if (((env->w - size->x) < 100) || ((env->h - size->y) < 100))
			break ;
		old = env->factor;
		env->factor += 0.0001;
		ft_transform2d(env);
	}
	lastopgoodsize(env);
}
