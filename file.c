/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:59:04 by pfichepo          #+#    #+#             */
/*   Updated: 2016/03/07 14:59:07 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "include/fdf.h"

void				checkread(char *s)
{
	int fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		error("CAN'T OPEN FILE");
	}
	close(fd);
}

t_point				*mapsize(t_env *env)
{
	t_point		*map;
	int			xmax;
	int			xmin;
	int			ymin;
	int			ymax;

	map = env->grid;
	xmax = map->x_2d;
	ymax = map->y_2d;
	xmin = map->x_2d;
	ymin = map->y_2d;
	while (map)
	{
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
	return (ft_ptsnew(xmax - xmin, ymax - ymin, 0));
}

t_point				*mapmin(t_env *env)
{
	t_point	*map;
	int		xmin;
	int		ymin;

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

t_point				*mapmax(t_env *env)
{
	t_point	*map;
	int		xmax;
	int		ymax;

	map = env->grid;
	xmax = map->x_2d;
	ymax = map->y_2d;
	while (map)
	{
		if (map->y_2d > ymax)
			ymax = map->y_2d;
		if (map->x_2d > xmax)
			xmax = map->x_2d;
		map = map->next;
	}
	map = (t_point*)malloc(sizeof(t_point));
	map->x = xmax;
	map->y = ymax;
	return (map);
}
