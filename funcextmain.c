/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcextmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:38:59 by pfichepo          #+#    #+#             */
/*   Updated: 2016/09/19 09:32:44 by pfichepo         ###   ########.fr       */
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

static void		drawinfo(t_env *env)
{
	char		buffer[255];
	char		buffer2[255];
	double		time1;
	double		time2;
	char		*a;

	a = ft_itoa(pointsnb(env->grid));
	time1 = (double)(clock() - env->time);
	time2 = (double)(env->timeend - env->timestart);
	mlx_string_put(env->mlx, env->win, 10, 10, 0xFFFFFF, "Points :");
	mlx_string_put(env->mlx, env->win, 110, 10, 0xFFFFFF, a);
	env->frametime = time1 / CLOCKS_PER_SEC;
	sprintf(buffer, "%.0f FPS", 1 / env->frametime);
	sprintf(buffer2, "Sec to proc : %.3f | ", time2 / CLOCKS_PER_SEC);
	mlx_string_put(env->mlx, env->win, 10, 40, 0xFFFFFF, buffer);
	mlx_string_put(env->mlx, env->win, 10, 70, 0xFFFFFF, buffer2);
}

int				draw(t_env *env)
{
	env->time = clock();
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, env->w, env->h);
	env->data = mlx_get_data_addr(env->img, &env->bpp, \
		&env->size_line, &env->endian);
	if (env->rendermode == 3)
		drawmap3d(env);
	else
		drawmap2d(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
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
	t_point		*size;
	double		old;

	old = env->factor;
	ft_transform2d(env);
	while (1)
	{
		size = mapsize(env);
		if (((env->w - size->x) < 0) || ((env->h - size->y) < 0))
		{
			if (old == 0.01)
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
