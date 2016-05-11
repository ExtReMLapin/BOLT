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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	error(const char *s)
{
	ft_putstr("\033[1;31m");
	ft_putstr("[FATAL ERROR] : ");
	ft_putstr(s);
	ft_putstr("\033[0m");
	ft_putchar('\n');
	exit(EXIT_FAILURE);
}

void	errornohalt(const char *s)
{
	ft_putstr("\033[1;31m");
	ft_putstr("[SPOOKY ERROR] : ");
	ft_putstr(s);
	ft_putstr("\033[0m");
	ft_putchar('\n');
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