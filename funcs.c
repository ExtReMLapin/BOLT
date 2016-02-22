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


inline int	fastmlx_pixel_put(t_env *env, int x, int y, int color)
{
	int h;
	int w;

	h = env->h;
	w = env->w;

	if ((x > w) || (x < 0))
		return (0);
	if ((y > h) || (y < 0))
		return (0);
	return (mlx_pixel_put(env->mlx, env->win, x, y, color));
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
			fastmlx_pixel_put(env, i2, b2, c);
			b++;
		}	
		i++;
	}
}


void ft_singlepointtrans(t_env *e, t_point *p)
{
		p->x_2d = (p->x * e->factor * 3) - (p->y * e->factor * 3) -
				(p->z / (16 * e->factor)) + (e->h / 2);
		p->y_2d = (p->x * e->factor * 2) + (p->y * e->factor * 2) -
			(p->z * (4 * e->factor)) - ((e->h * e->factor) -
					(100 * e->factor));

		p->x_2d += e->offsetx;
		p->y_2d += e->offsety;

		//printf("YOLO %i  %i\n", p->x_2d, p->y_2d   );

}




void		ft_transform2d(t_env *e)
{
	t_point *p;

	p = e->grid;

	while (p)
	{
		ft_singlepointtrans(e, p);
		p = p->next;
	}
}


float math_remap(int value, int inMin,int inMax, int outMin, int outMax )
{
	return (outMin + (((value - inMin)/(inMax-inMin))*(outMax - outMin)));
}


int tblmax(int **tbl, int choice)
{
	int i;

	i = 0;
	if (choice == 1)
	{
		while (tbl[i])
			i++;
		return (i);
	}

	if (tbl[0])
	{
		while (tbl[0][i] != INTBLTLIMIT)
			i = i + 1;
		return(i);
	}
	return (1);
}

t_point *mapsize(t_env *env)
{
	t_point *map;
	int xmax;
	int xmin;
	int ymin;
	int ymax;
	map = env->grid;
	xmax = map->x_2d;
	ymax = map->y_2d;
	xmin = map->x_2d;
	ymin = map->y_2d;
	while (map)
	{
		//printf("%i , %i\n",map->x_2d, map->y_2d);
		if (map->y_2d < ymin)
			ymin = map->y_2d;
		if (map->y_2d > ymax)
			ymax = map->y_2d;
		if (map->x_2d < xmin)
			xmin = map->x_2d;
		if (map->x_2d > xmax)
			xmax = map->x_2d;
		map = map->next;

	}

	map = (t_point*)malloc(sizeof(t_point));
	//printf("%i , %i, %i, %i\n",xmin, xmax, ymin, ymax );
	map->x = xmax-xmin;
	map->y = ymax-ymin;
	return (map);
}

t_point *mapmin(t_env *env)
{
	t_point *map;
	int xmin;
	int ymin;

	map = env->grid;
	xmin = map->x_2d;
	ymin = map->y_2d;
	while (map)
	{
		if (map->y_2d < ymin)
			ymin = map->y_2d;
		if (map->x_2d < xmin)
			xmin = map->x_2d;
		map = map->next;

	}

	map = (t_point*)malloc(sizeof(t_point));
	map->x = xmin;
	map->y = ymin;
	return (map);
}
